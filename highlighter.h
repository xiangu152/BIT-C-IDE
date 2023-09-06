#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H
#include<QSyntaxHighlighter>
#include<QTextCharFormat>
#include<QRegularExpression>


class Highlighter : public QSyntaxHighlighter
{
public:
    Highlighter(QTextDocument* parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;

private:

    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;
    QTextCharFormat keywordFormat;
    QTextCharFormat explanFormate;
    QTextCharFormat citationFormate;
    QTextCharFormat functionFormat;
    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat numberFormat;

    QTextCharFormat anglebracketsFormat;


};

#endif // HIGHLIGHTER_H
