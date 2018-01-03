#pragma once

/*
* Author	: huanghefu (Opensource)
* Project	: https://github.com/hefuhuang/httpQTvtkSeverClient
* QQ     	: 1966423770
* 单例类
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef _NETUTIL_H_
#define _NETUTIL_H_

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

#include "netutil_global.h"
class QNetworkReply;

class NETUTIL_EXPORT NetUtil:public QObject
{
	Q_OBJECT 
public:
   static NetUtil *instance(); 
	~NetUtil();  
	void Get(const QString &Url);  // excute HTTP GET

signals:
	void Finished(QNetworkReply *m_Reply);

private:
	class Private;
	friend class Private;   // 嵌套类
	Private *m_Private; 
	explicit NetUtil(QObject *parent = 0);   ///explicit的构造函数不能在隐式转换中使用
	NetUtil(const NetUtil &) Q_DECL_EQ_DELETE; // 复制构造函数参数为类对象本身的引用，用于根据一个已存在的对象复制出一个新的该类的对象，一般在函数中会将已存在对象的数据成员的值复制一份到新创建的对象中

	NetUtil& operator=(NetUtil rhs)Q_DECL_EQ_DELETE;  // 注意，这个类似复制构造函数，将=右边的本类对象的值复制给等号左边的对象，它不属于构造函数，等号左右两边的对象必须已经被创建

};



#endif 