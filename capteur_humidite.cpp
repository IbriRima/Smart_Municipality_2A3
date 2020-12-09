#include "capteur_humidite.h"

Capteur_humidite::Capteur_humidite()
{

}
int Capteur_humidite::connect_capteur_humidite()
{

    foreach(const QSerialPortInfo & serial_port_info,QSerialPortInfo::availablePorts())
    {if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
        if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_producy_id)
        {
         arduino_is_available=true;
         arduino_port_name=serial_port_info.portName();

        }
        }
    }
    qDebug()<<"Arduino port name is: "<<arduino_port_name;
    if(arduino_is_available)
    {  qDebug()<<  QSerialPort::SerialPortError();
        serial->setPortName(arduino_port_name);

        if(serial->open(QSerialPort::ReadWrite))
        {

           serial-> setBaudRate(QSerialPort::Baud9600); //débit: 9600bits/s
           serial-> setDataBits(QSerialPort::Data8);  //Longueur des données : 8bits
           serial-> setParity(QSerialPort::NoParity); //1 bit de parité optionnel
           serial-> setStopBits(QSerialPort::OneStop); //nombre de bits de stop
           serial-> setFlowControl(QSerialPort::NoFlowControl);
        return 0;
        }
        return 1;
    }
    return -1;
}
int Capteur_humidite::close_Capteur_humidite()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;

    }
    return 1;
}
int Capteur_humidite::write_to_capteur_humidite(QByteArray d)
{
    if(serial->isWritable())
    {
        serial->write(d);

    }
    else qDebug()<<"Couldn't write to serial";

}
 QByteArray Capteur_humidite:: read_from_capteur_humidite()
{
     if(serial-> isReadable())
     {
         data=serial->readAll();
         return data;
     }

 }
  QString Capteur_humidite::get_capteur_humidite_port_name()
  {
      return arduino_port_name;
  }
    QSerialPort* Capteur_humidite:: getserial()
    {
        return serial;
    }
