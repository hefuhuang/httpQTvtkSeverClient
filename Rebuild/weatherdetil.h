#ifndef WEATHERDETIL_H
#define WEATHERDETIL_H

#include <QString> 
#include <QDateTime>
#include <QDebug> 

namespace Detil
{
class WeatherDetil
{
public:
	WeatherDetil();
	~WeatherDetil();
	QString desc() const;
	void SetData(const QString &desc); 
	QString Icon() const; 
	void SetIcon(const QString &icon);

private: 
	class Private;
	friend class Private;
	Private *m_private;

};
}

class WeatherInfo
{
public: 
	WeatherInfo();
	~WeatherInfo();
	QString CityName();
	void SetCityName(const QString &cityName);

private:
	quint32 Id() const;
	void SetId(quint32 id); 
	QDateTime datatime() const; 
	void SetDateTime(const QDateTime &dateTime);

	float temperature() const; 
	void SetTemperature(float temperature); 

	float humidity() const;
	void SetHumidity(float humidity);

	float pressure() const;
	void SetPressure(float pressure); 

private:
	class Private;
	friend class Private;
	Private *m_private;

};


#endif // WEATHERDETIL_H
