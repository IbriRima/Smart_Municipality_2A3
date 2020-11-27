#include "evenement.h"
#include <QChartGlobal>
#include <QChartView>
#include<QtCharts>
#include<QChart>
#include<QtChartsDepends>
#include<QtChartsVersion>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

Evenement::Evenement()
{

}

Evenement::Evenement(QString id,QString nom,QString type,QString date,QString horaire,QString empl ,QString etat )
{
    this->Id_event=id;
    this->Nom_event=nom;
    this->Type_event=type;
    this->Date_event=date;
    this->Horaire_event=horaire;
    this->Empl_event=empl;
    this->Etat_event=etat;

}

bool Evenement::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EVENEMENT (ID_EVENT,NOM_EVENT,TYPE_EVENT,DATE_EVENT,HOR_EVENT,EMPL_EVENT,ETAT_EVENT)"" VALUES(:Id_event, :Nom_event, :Type_event, :Date_event,:Horaire_event,:Empl_event,:Etat_event)");
    query.bindValue(":Id_event",Id_event);
    query.bindValue(":Nom_event",Nom_event);
    query.bindValue(":Type_event",Type_event);
    query.bindValue(":Date_event",Date_event);
    query.bindValue(":Horaire_event",Horaire_event);
    query.bindValue(":Empl_event",Empl_event);
    query.bindValue(":Etat_event",Etat_event);
    return query.exec();

}

bool Evenement::controle()
{
   if(Id_event=="")  return false;
   else            return true;


}

bool Evenement::supprimer(QString Id_event)
{
   QSqlQuery query;
   query.prepare("DELETE FROM EVENEMENT WHERE ID_EVENT= :id");
   query.bindValue(":id",Id_event);
   return query.exec();

}

QSqlQueryModel * Evenement::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select *from Evenement");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EVENT"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EVENT"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_EVENT"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EVENT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("HORAIRE_EVENT"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMPL_EVENT"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT_EVENT"));

       return model;
}
bool Evenement::maj(QString old_id)
{
    QSqlQuery qry;

    qry.prepare("UPDATE EVENEMENT SET ID_EVENT=:id, NOM_EVENT=:Nom_event, TYPE_EVENT=:Type_event,DATE_EVENT=:Date_event, HOR_EVENT=:Hor_event,EMPL_EVENT=:Empl_event,ETAT_EVENT=:Etat_event WHERE ID_EVENT =:old_id ");
    qry.bindValue(":id",Id_event);
    qry.bindValue(":Nom_event",Nom_event);
    qry.bindValue(":Type_event",Type_event);
    qry.bindValue(":Date_event",Date_event);
    qry.bindValue(":Hor_event",Horaire_event);
    qry.bindValue(":Empl_event",Empl_event);
    qry.bindValue(":Etat_event",Etat_event);
    qry.bindValue(":old_id",old_id);

     if(!qry.exec()){
         QMessageBox::critical(nullptr, QObject::tr("mise à jour non effectuée"),
                     QObject::tr("reéssayez plus tard"), QMessageBox::Ok);
         return false;
     }
     else{
         qDebug("Values added to DB");
         return true;
     }
 }
QSqlQueryModel * Evenement::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM EVENEMENT ORDER BY TYPE_EVENT ;");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EVENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EVENT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_EVENT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_EVENT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("HORAIRE_EVENT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMPL_EVENT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT_EVENT"));


    return model;
}
/*double Evenement::total()
{

       QSqlQuery query("SELECT COUNT (*) FROM EVENEMENT");
       query.next();
       double nbevent = query.value(0).toDouble();
       return nbevent;

}



void Evenement::setData(QVector<double> value, QVector<QColor> color)
{
    qvValue=value;
    qvColor=color;
    //repaint();
   // update();
}

void Evenement::paintEvent(QPaintEvent *)

{
    QPainter painter(this);
    QPen pen;
    QRectF size;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    if (this->height() > this->width())
   {

        size =QRectF(10,10,this->width()-10,this->width()-10);
    }
    else
    {
        size =QRectF(10,10,this->height()-10,this->height()-10);
    }
    double sum=total(); double startAng =0.0;
    double angle, endAng, percent ;
    for(int i=0; i<qvValue.size(); i++)
    {
        percent= qvValue[i] / sum;
        angle = percent * 360.0;
        endAng = startAng + angle;
        painter.setBrush(qvColor[i]);
        painter.drawPie(size,startAng*16,angle*16);
        startAng=endAng;
    }

}

*/
void Evenement::statistiques()
{
    // Assign names to the set of bars used

           QBarSet *set0 = new QBarSet("Altuve");
           QBarSet *set1 = new QBarSet("Martinez");
           QBarSet *set2 = new QBarSet("Segura");
           QBarSet *set3 = new QBarSet("Simmons");
           QBarSet *set4 = new QBarSet("Trout");

           // Assign values for each bar
           *set0 << 283 << 341 << 313 << 338 << 346 << 335;
           *set1 << 250 << 315 << 282 << 307 << 303 << 330;
           *set2 << 294 << 246 << 257 << 319 << 300 << 325;
           *set3 << 248 << 244 << 265 << 281 << 278 << 313;
           *set4 << 323 << 287 << 299 << 315 << 306 << 313;

           // Add all sets of data to the chart as a whole
           // 1. Bar Chart
           QBarSeries *series = new QBarSeries();

           // 2. Stacked bar chart
           // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
           series->append(set0);
           series->append(set1);
           series->append(set2);
           series->append(set3);
           series->append(set4);

           // Used to define the bar chart to display, title
           // legend,
           QChart *chart = new QChart();

           // Add the chart
           chart->addSeries(series);

           // Set title
           chart->setTitle("Batting Avg by Year");

           // Define starting animation
           // NoAnimation, GridAxisAnimations, SeriesAnimations
           chart->setAnimationOptions(QChart::AllAnimations);

           // Holds the category titles
           QStringList categories;
           categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

           // Adds categories to the axes
           QBarCategoryAxis *axis = new QBarCategoryAxis();
           axis->append(categories);
           chart->createDefaultAxes();

           // 1. Bar chart
           chart->setAxisX(axis, series);

           // 2. Stacked Bar chart
           // chart->setAxisY(axis, series);

           // Define where the legend is displayed
           chart->legend()->setVisible(true);
           chart->legend()->setAlignment(Qt::AlignBottom);

           // Used to display the chart
           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);

           // Used to change the palette
           QPalette pal = qApp->palette();

           // Change the color around the chart widget and text
           pal.setColor(QPalette::Window, QRgb(0xffffff));
           pal.setColor(QPalette::WindowText, QRgb(0x404044));

           // Apply palette changes to the application
           qApp->setPalette(pal);



           // 3. Line chart example
           // Other options here https://doc.qt.io/qt-5.11/qtcharts-customchart-example.html

          /* QLineSeries *series = new QLineSeries();
           series->append(0, 16);
           series->append(1, 25);
           series->append(2, 24);
           series->append(3, 19);
           series->append(4, 33);
           series->append(5, 25);
           series->append(6, 34);

           // Create chart, add data, hide legend, and add axis
           QChart *chart = new QChart();
           chart->legend()->hide();
           chart->addSeries(series);
           chart->createDefaultAxes();

           // Customize the title font
           QFont font;
           font.setPixelSize(18);
           chart->setTitleFont(font);
           chart->setTitleBrush(QBrush(Qt::black));
           chart->setTitle("Barry Bonds HRs as Pirate");

           // Change the line color and weight
           QPen pen(QRgb(0x000000));
           pen.setWidth(5);
           series->setPen(pen);

           chart->setAnimationOptions(QChart::AllAnimations);

           // Change the x axis categories
           QCategoryAxis *axisX = new QCategoryAxis();
           axisX->append("1986",0);
           axisX->append("1987",1);
           axisX->append("1988",2);
           axisX->append("1989",3);
           axisX->append("1990",4);
           axisX->append("1991",5);
           axisX->append("1992",6);
           chart->setAxisX(axisX, series);

           // Used to display the chart
           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);
          */
}

QSqlQuery Evenement::select(QString ID)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EVENEMENT WHERE ID_EVENT='"+ID+"'");
    return query;
}
