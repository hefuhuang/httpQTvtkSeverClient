#pragma once

/*
* Author	: huanghefu (Opensource)
* Project	: https://github.com/hefuhuang/httpQTvtkSeverClient
* QQ     	: 1966423770
* ������
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
	friend class Private;   // Ƕ����
	Private *m_Private; 
	explicit NetUtil(QObject *parent = 0);   ///explicit�Ĺ��캯����������ʽת����ʹ��
	NetUtil(const NetUtil &) Q_DECL_EQ_DELETE; // ���ƹ��캯������Ϊ�����������ã����ڸ���һ���Ѵ��ڵĶ����Ƴ�һ���µĸ���Ķ���һ���ں����лὫ�Ѵ��ڶ�������ݳ�Ա��ֵ����һ�ݵ��´����Ķ�����

	NetUtil& operator=(NetUtil rhs)Q_DECL_EQ_DELETE;  // ע�⣬������Ƹ��ƹ��캯������=�ұߵı�������ֵ���Ƹ��Ⱥ���ߵĶ����������ڹ��캯�����Ⱥ��������ߵĶ�������Ѿ�������

};



#endif 