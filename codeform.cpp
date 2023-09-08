#include "codeform.h"
#include "ui_codeform.h"
#include"highlighter.h"
#include<QMessageBox>
#include<QtDebug>

int position=0;
CodeForm::CodeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CodeForm)
{
    ui->setupUi(this);
    ui->searchForm->hide();
    ui->replaceform->hide();
    Highlighter* highlighter = new Highlighter(ui->text_widget->document());
    connect(ui->searchForm,SIGNAL(startSearch(QString)),this,SLOT(start_search(QString)));
    connect(ui->searchForm,SIGNAL(stopSearch(QString)),this,SLOT(stop_search(QString)));
    connect(ui->searchForm,SIGNAL(searchNext(QString)),this,SLOT(search_Next(QString)));
    connect(ui->replaceform,SIGNAL(replace(QString,QString)),this,SLOT(replace_func(QString,QString)));
    connect(ui->text_widget,SIGNAL(textChanged()),this,SLOT(isChanged()));

}

CodeForm::~CodeForm()
{
    delete ui;

}

CodeForm* CodeForm::getWidget()
{
    return this;
}

void CodeForm::setText(QString str)
{
    ui->text_widget->setPlainText(str);
}

QString CodeForm::getText()
{
    return ui->text_widget->toPlainText();
}

void CodeForm::isChanged()
{
    if(is_change==false)
        is_change=true;
}

void CodeForm::paste()
{
    ui->text_widget->paste();
}

void CodeForm::cut()
{
    ui->text_widget->cut();
}

void CodeForm::withdraw()
{
    ui->text_widget->undo();
}

void CodeForm::recover()
{
    ui->text_widget->redo();
}

void CodeForm::copy()
{
    ui->text_widget->copy();
}

void CodeForm::all_select()
{
    ui->text_widget->selectAll();
}

void CodeForm::searchStart()
{
    ui->searchForm->show();
}

void CodeForm::replaceStart()
{
    ui->replaceform->show();
}

void CodeForm::start_search(QString(searchtext))
{
    QString search_text = searchtext;
     qDebug()<<search_text;
    if(!search_text.trimmed().isEmpty())
    {
            bool found = false;
            qDebug()<<ui->text_widget->document();
            QTextDocument *document = ui->text_widget->document();
            QTextCursor mark_cursor(document);
            QTextCursor cursor(document);
            cursor.beginEditBlock();
            QTextCharFormat mark_formate(mark_cursor.charFormat());
            mark_formate.setForeground(Qt::red);
            mark_formate.setFontUnderline(true);
           // mark_formate.setBackground(Qt::blue);
            while(!mark_cursor.isNull()&&!mark_cursor.atEnd())
            {
                mark_cursor = document->find(search_text,mark_cursor);
                  if(!mark_cursor.isNull())
                  {
                      if (!found) found = true;
                      mark_cursor.mergeCharFormat(mark_formate);
                  }
            }
            if(!found)
                QMessageBox::warning(this, "Warning!", "没有找到指定内容", QMessageBox::Yes);
            cursor.endEditBlock();
    }
    else
    {
        if (search_text.trimmed().isEmpty())
                 QMessageBox::information(this, "Infomation", "输入内容不能为空", QMessageBox::Yes);
    }

}

void CodeForm::search_Next(QString(searchtext))
{
    QString search_text = searchtext;


        //清除原有标记
        if(!search_text.trimmed().isEmpty())
        {
                bool found = false;
                QTextDocument *document = ui->text_widget->document();
                QTextCursor mark_cursor(document);
                QTextCursor cursor(document);
                cursor.beginEditBlock();
                QTextCharFormat mark_formate(mark_cursor.charFormat());
                mark_formate.setForeground(Qt::black);
                mark_formate.setFontUnderline(false);
               // mark_formate.setBackground(Qt::blue);
                while(!mark_cursor.isNull()&&!mark_cursor.atEnd())
                {
                    mark_cursor = document->find(search_text,mark_cursor);
                      if(!mark_cursor.isNull())
                      {
                          if (!found) found = true;
                          mark_cursor.mergeCharFormat(mark_formate);
                      }
                }
                cursor.endEditBlock();
        }



        if(!search_text.trimmed().isEmpty())
        {
                bool found = false;
                qDebug()<<ui->text_widget->document();
                QTextDocument *document = ui->text_widget->document();
                QTextCursor mark_cursor(document);


                QTextCharFormat mark_formate(mark_cursor.charFormat());
                mark_formate.setForeground(Qt::red);
                mark_formate.setFontUnderline(true);
               // mark_formate.setBackground(Qt::blue);

                QString text = ui->text_widget->toPlainText();

                position = text.indexOf(searchtext, position);
                if(!mark_cursor.isNull()&&!mark_cursor.atEnd())
                {
                      mark_cursor = document->find(search_text,position);
                      if(!mark_cursor.isNull())
                      {
                          if (!found) found = true;
                          mark_cursor.mergeCharFormat(mark_formate);
                      }
                      position=position+searchtext.length();

                }

                if(!found)
                    QMessageBox::warning(this, "Warning!", "找不到更多 \"" + searchtext + "\"..." ,QMessageBox::Yes);

        }
        else
        {
            if (search_text.trimmed().isEmpty())
                     QMessageBox::information(this, "Infomation", "输入内容不能为空", QMessageBox::Yes);
        }

        //int location = edittext.length();
       // edittext.setSelection(location)


    }








void CodeForm::stop_search(QString(searchtext))
{
    QString search_text = searchtext;
     qDebug()<<search_text;
    if(!search_text.trimmed().isEmpty())
    {
            bool found = false;
            QTextDocument *document = ui->text_widget->document();
            QTextCursor mark_cursor(document);
            QTextCursor cursor(document);
            cursor.beginEditBlock();
            QTextCharFormat mark_formate(mark_cursor.charFormat());
            mark_formate.setForeground(Qt::black);
            mark_formate.setFontUnderline(false);
           // mark_formate.setBackground(Qt::blue);
            while(!mark_cursor.isNull()&&!mark_cursor.atEnd())
            {
                mark_cursor = document->find(search_text,mark_cursor);
                  if(!mark_cursor.isNull())
                  {
                      if (!found) found = true;
                      mark_cursor.mergeCharFormat(mark_formate);
                  }
            }
            cursor.endEditBlock();
    }
}

void  CodeForm::replace_func(QString old_l,QString new_l)
{
    bool found = false;
    if (old_l.trimmed().isEmpty()&&new_l.trimmed().isEmpty())
         QMessageBox::warning(this, "Warning!", "输入内容不能为空", QMessageBox::Yes);
    else
    {
        QTextDocument *document = ui->text_widget->document();
        QTextCursor replace_cursor(document);
        QTextCursor cursor(document);
        cursor.beginEditBlock();
        while(!replace_cursor.isNull()&&!replace_cursor.atEnd())
        {
              replace_cursor = document->find(old_l,replace_cursor);
              if(!replace_cursor.isNull())
              {
                  if (!found) found = true;
                  replace_cursor.removeSelectedText();
                  replace_cursor.insertText(new_l);
              }
        }
        cursor.endEditBlock();
        if(!found)
            QMessageBox::warning(this, "Warning!", "没有找到指定内容", QMessageBox::Yes);
        else
        {
            QMessageBox::warning(this, "Information!", "替换成功", QMessageBox::Yes);
            //ui->replaceform->close();
        }
    }
}

QFont CodeForm::Font()
{
    return ui->text_widget->getFont();
}

void CodeForm::setFont(QFont f)
{
    ui->text_widget->setFont(f);
}
void CodeForm::setRunSetting(bool ok)
{
    if(ok==true)
        ui->IO_widget->hide();
    else
        ui->IO_widget->show();
}

void CodeForm::handleButtonClick()
{
    deletedLines.clear();
          QString inputText = ui->text_widget->toPlainText(); // 获取输入框的内容
               QTextDocument* document = ui->text_widget->document();
               int lineCount = document->blockCount();
               int startLine = 0;
               int endLine = 0;
               int i = 0;
               int start = 0;
               int end = 0;


               // 遍历所有行
               for (int lineNumber = 0; lineNumber < lineCount; ++lineNumber) {
                   QTextBlock block = document->findBlockByNumber(lineNumber);
                   QString lineText = block.text();

                   // 处理当前行
                   if (lineText.contains("void")) {
                       i++;
                       // 记录包含 "void" 的行号
                       startLine = lineNumber+1;
         //              qDebug() << startLine;

                   }
                   // 处理当前行
                   if (lineText.contains("}")) {
                       // 记录包含 "void" 的行号
                       endLine = lineNumber+1;
         //              qDebug() << endLine;

                   }
         //          qDebug() << lineNumber;

                   if(startLine >=1 && endLine >=1 && start != startLine && end != endLine){
                       start = startLine;
                       end = endLine;
                       qDebug() << startLine   << endLine ;
                       QTextBlock startBlock = document->findBlockByNumber(startLine - 1);
                       QTextBlock endBlock = document->findBlockByNumber(endLine - 1);

                       // 遍历 startBlock 到 endBlock 之间的所有行
                       for (QTextBlock currentBlock = startBlock.next(); currentBlock.isValid() && currentBlock.blockNumber() <= endBlock.blockNumber(); currentBlock = currentBlock.next()) {
                           int currentLineNumber = currentBlock.blockNumber() + 1;
                           QString currentLineText = currentBlock.text();

                           deletedLines.append(qMakePair(currentLineNumber, currentLineText));
                           // 使用迭代器删除当前行内的文本
                           QTextCursor cursor(currentBlock);
                           cursor.beginEditBlock();
                           cursor.movePosition(QTextCursor::StartOfBlock);
                           cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
                           cursor.removeSelectedText();
                           cursor.endEditBlock();
                       }
                        addContent(startLine-1,".....}");
                   }

               }
               // 打印被删除的行号和文本内容
               for (const QPair<int, QString>& linePair : deletedLines) {
                   int lineNumber = linePair.first;
                   QString lineText = linePair.second;
                   qDebug() << "Deleted line: " << lineNumber << lineText;
               }

}

void CodeForm::addContent(int line,QString content){
      QTextCursor cursorAdd(ui->text_widget->document());
      cursorAdd.movePosition(QTextCursor::Start);
      cursorAdd.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, line);
      cursorAdd.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
      cursorAdd.insertText(content);
}

void CodeForm::changeFold()
{
    if (!is_fold) {
            // 折叠函数
            handleButtonClick();
        }
    else {
            // 重新赋值已删除的行到输入框
            QTextDocument* document = ui->text_widget->document();

            for (const QPair<int, QString>& linePair : deletedLines) {
                int lineNumber = linePair.first;
                QString lineText = linePair.second;

                QTextBlock block = document->findBlockByNumber(lineNumber - 1);
                QTextCursor cursor(block);
                cursor.movePosition(QTextCursor::EndOfBlock);
                cursor.insertText(lineText);
            }
            QTextDocument* documentR = ui->text_widget->document();
            QString text = documentR->toPlainText();
            text.replace(".....}", "");
            document->setPlainText(text);

        }
}
