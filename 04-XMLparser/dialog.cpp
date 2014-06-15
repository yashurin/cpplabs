#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    index(0)
{
    ui->setupUi(this);

    text = new QTextEdit;
    readMyXML();
    text->append("<b>Id: </b>" + data[0].id);
    text->append("<b>Student Card: </b>" + data[0].card1);
    text->append("<b>Name: </b>" + data[0].name);
    text->append("<b>Year of Birth: </b>" + data[0].year);
    text->append("<b>Specialization: </b>" + data[0].spec);
    text->append("<b>Average Grade: </b>" + data[0].avgrade);
    text->setReadOnly(true);

    label = new QLabel;
    for (int i = 0; i < N; i++)
        img_list.append(QImage(":/new/prefix1/student" + QString::number(i) +
                          ".jpg"));
    img_cur = img_list[index].scaled(150, 200);
    label->setPixmap(QPixmap::fromImage(img_cur));

    next = new QPushButton("Next");
    prev = new QPushButton("Previous");


    hlay = new QHBoxLayout;
    vlay = new QVBoxLayout;

    hlay->addWidget(text);
    hlay->addLayout(vlay);

    vlay->addWidget(label);

    vlay->addWidget(next);
    vlay->addWidget(prev);

    setLayout(hlay);

    connect(next, SIGNAL(clicked()), this, SLOT(slotNext()));
    connect(prev, SIGNAL(clicked()), this, SLOT(slotPrev()));
}
void Dialog::readMyXML(void)
{

    QFile * file = new QFile("/home/andrei/Documents/qt/xmlprsr/students.xml");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox mess;
        mess.setText("XML file cannot be opened");
        mess.exec();
        return;
    }
    QXmlStreamReader xml(file);
    QXmlStreamReader::TokenType token;
    Stud temp;
    while (!xml.atEnd() && !xml.hasError())
    {
        token=xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement)
        {
            if (xml.name() == "students")
                continue;

            if (xml.name() == "stud")
            {
                QXmlStreamAttributes attrs = xml.attributes();
                if (attrs.hasAttribute("id"))
                    temp.id=attrs.value("id").toString();
                continue;
            }

            if (xml.name() == "card1")
            {
                xml.readNext();
                temp.card1=xml.text().toString();
                continue;
            }

            if (xml.name() == "name")
            {
                xml.readNext();
                temp.name=xml.text().toString();
                continue;
            }

            if (xml.name() == "year")
            {
                xml.readNext();
                temp.year=xml.text().toString();
                continue;
            }

            if (xml.name() == "spec")
            {
                xml.readNext();
                temp.spec=xml.text().toString();
                continue;
            }

            if (xml.name() == "avgrade")
            {
                xml.readNext();
                temp.avgrade=xml.text().toString();
                continue;
            }

        }
        if (token == QXmlStreamReader::EndElement)
        {
            if (xml.name() == "stud")
            {
                data.append(temp);
            }
        }
    }
}

void Dialog::slotNext()
{
    if (index < N -1)
    {
        index++;
        img_cur = img_list[index].scaled(120, 170);
        label->setPixmap(QPixmap::fromImage(img_cur));
        text->clear();
        text->append("<b>Id: </b>" + data[index].id);
        text->append("<b>Student Card: </b>" + data[index].card1);
        text->append("<b>Name: </b>" + data[index].name);
        text->append("<b>Year of Birth: </b>" + data[index].year);
        text->append("<b>Specialization: </b>" + data[index].spec);
        text->append("<b>Average Grade: </b>" + data[index].avgrade);
    }
}
void Dialog::slotPrev()
{
    if (index>0)
    {
        index--;
        img_cur = img_list[index].scaled(120, 170);
        label->setPixmap(QPixmap::fromImage(img_cur));
        text->clear();
        text->append("<b>Id: </b>" + data[index].id);
        text->append("<b>Student Card: </b>" + data[index].card1);
        text->append("<b>Name: </b>" + data[index].name);
        text->append("<b>Year of Birth: </b>" + data[index].year);
        text->append("<b>Specialization: </b>" + data[index].spec);
        text->append("<b>Average Grade: </b>" + data[index].avgrade);
    }
}


Dialog::~Dialog()
{
    delete ui;
}
