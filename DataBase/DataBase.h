/*
* Author	: huanghefu (Opensource)
* Project	: https://github.com/hefuhuang/httpQTvtkSeverClient
* QQ     	: 1966423770
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#pragma once
#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <string>
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QtDebug>
#include <QSqlTableModel>
#include <QTableView> 
#include <QHeaderView>
#include <QMessageBox>

#include "database_global.h"

class DATABASE_EXPORT DataBase
{
public:
    DataBase();
	~DataBase();
	void CreateTable(std::string fileDataBase);
	void CreateDBTable(std::string fileDataBase,std::string DBCommand);

	bool ModelOperateDatabase(std::string fielPath);
	bool Connect(const QString &dbName);
	void VisualDataBase(std::string fielPath);
	void PrintInfo(QSqlQuery m_Query,std::string DBCommand);

private: 
	std::string filepath;
	enum ColumnIndex
	{
		Column_ID = 0,
		Column_Name = 1,
		Column_Age = 2
	};
};

#endif 