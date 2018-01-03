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
NetWorker::Private需要其被辅助的类NetWorker的指针，
目的是作为QNetworkAccessManager的 parent，以便NetWorker
析构时能够自动将QNetworkAccessManager析构。当然，我们也可以
通过将NetWorker::Private声明为QObject的子类来达到这一目的。
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
线程安全  C++标准构造函数不能被打断
*/
NetUtil *NetUtil::instance()
{
	static NetUtil m_NetUtil;
	return &m_NetUtil;
}
/*
将QNetworkAccessManager的finished()信号进行转发。也就是说，当QNetworkAccessManager发出finished()信号时，
NetWorker同样会发出自己的finished()信号。析构函数将 dm_Private指针删除。由于NetWorker::Private是在堆上创建的，
并且没有继承QObject，所以我们必须手动调用delete运算符。 
*/
NetUtil::NetUtil(QObject *parent) :QObject(parent), m_Private(new NetUtil::Private(this))
{
	connect(m_Private->manager,&QNetworkAccessManager::finished,this,&NetUtil::Finished);   // 信号槽
}

NetUtil::~NetUtil()
{
	delete m_Private;
	m_Private = 0;
}
/*
直接将网址提供给底层  便可访问url
*/

void NetUtil::Get(const QString &url)    
{
	m_Private->manager->get(QNetworkRequest(QUrl(url)));
}


