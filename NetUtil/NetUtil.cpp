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
#include <QNetworkReply>
#include "NetUtil.h"

/*
NetWorker::Private��Ҫ�䱻��������NetWorker��ָ�룬
Ŀ������ΪQNetworkAccessManager�� parent���Ա�NetWorker
����ʱ�ܹ��Զ���QNetworkAccessManager��������Ȼ������Ҳ����
ͨ����NetWorker::Private����ΪQObject���������ﵽ��һĿ�ġ�
*/
class NetUtil::Private   
{
public: 
	Private(NetUtil *q):manager(new QNetworkAccessManager(q))
	{
	};
	QNetworkAccessManager* manager;
};
/*  
�̰߳�ȫ  C++��׼���캯�����ܱ����
*/
NetUtil *NetUtil::instance()
{
	static NetUtil m_NetUtil;
	return &m_NetUtil;
}
/*
��QNetworkAccessManager��finished()�źŽ���ת����Ҳ����˵����QNetworkAccessManager����finished()�ź�ʱ��
NetWorkerͬ���ᷢ���Լ���finished()�źš����������� dm_Privateָ��ɾ��������NetWorker::Private���ڶ��ϴ����ģ�
����û�м̳�QObject���������Ǳ����ֶ�����delete������� 
*/
NetUtil::NetUtil(QObject *parent) :QObject(parent), m_Private(new NetUtil::Private(this))
{
	connect(m_Private->manager,&QNetworkAccessManager::finished,this,&NetUtil::Finished);   // �źŲ�
}

NetUtil::~NetUtil()
{
	delete m_Private;
	m_Private = 0;
}
/*
ֱ�ӽ���ַ�ṩ���ײ�  ��ɷ���url
*/

void NetUtil::Get(const QString &url)    
{
	m_Private->manager->get(QNetworkRequest(QUrl(url)));
}


