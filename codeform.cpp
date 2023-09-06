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
