#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bif\\b" << "\\bint\\b" << "\\bfor\\b"  << "\\bdo\\b"
                    << "\\bnew\\b" << "\\btry\\b" << "\\basm\\b" << "\\belse\\b"
                    << "\\bchar\\b" << "\\bfloat\\b" << "\\blong\\b" << "\\bvoid\\b"
                    << "\\bshort\\b" << "\\bwhile\\b" << "\\bdouble\\b" << "\\bbreak\\b"
                    << "\\btypedef\\b" << "\\bregister\\b" << "\\bcontinue\\b" << "\\bcatch\\b"
                    << "\\bsigned\\b" << "\\bunsigned\\b" << "\\bauto\\b" << "\\bstatic\\b"
                    << "\\bextern\\b" << "\\bsizeof\\b" << "\\bdelete\\b" << "\\bthrow\\b"
                    << "\\bconst\\b" << "\\bclass\\b" << "\\bfriend\\b" << "\\breturn\\b"
                    << "\\bswitch\\b" << "\\bpublic\\b" << "\\bunion\\b" << "\\bgoto\\b"
                    << "\\boperator\\b" << "\\btemplate\\b" << "\\benum\\b" << "\\bprivate\\b"
                    << "\\bvolatile\\b" << "\\bthis\\b" << "\\bvirtual\\b" << "\\bcase\\b"
                    << "\\bdefault\\b" << "\\binline\\b" << "\\bprotected\\b" << "\\bstruct\\b"
                    << "\\bexplicit\\b" << "\\bnamespace\\b" << "\\busing\\b" << "\\btypename\\b"
                    << "\\bbool\\b";
    foreach (const QString &pattern, keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    //被引号引用的部分,用绿色显示
    citationFormate.setForeground(Qt::darkGreen);
    citationFormate.setFontWeight(QFont::Bold);
    citationFormate.setFontItalic(true);
    rule.pattern = QRegularExpression("\".*\"");
    rule.format =  citationFormate;
    highlightingRules.append(rule);



    //被//的注释的部分用红色显示
    explanFormate.setForeground(Qt::red);
    explanFormate.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("//[^\n]*");
    rule.format  = explanFormate;
    highlightingRules.append(rule);

    numberFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression("\\b((0x[A-Fa-f0-9]*)|(\\d+(\\.\\d+)?)|(\\d+))\\b");
    rule.format = numberFormat;
    highlightingRules.append(rule);

    anglebracketsFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression("\x003C.*\x003E");
    rule.format = anglebracketsFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::red);
    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");

}



void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules)
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext())
        {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1){
        startIndex = text.indexOf(commentStartExpression);
    }

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}











