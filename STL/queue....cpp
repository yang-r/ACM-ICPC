1.vector
vector<int> v[10];
v[i].push_back(1);
v[i].size();
2.set/multiset
set<string> s;
s.insert("acm");
set<string>::iterator it;
for (it = country.begin(); it != country.end(); ++it) {
    cout << * it  << " ";
}
s.erase("acm");//ɾ��Ԫ��
s.count("acm");//ͳ�Ƹ���
s.clear();//��ռ���
3.map/multimap
map<string, int> m;
m["acm"] = 2;
m.count("acm");
for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
    cout << it->first << " is in class " << it->second << endl;
}
dict.clear();
4.stack
stack<int> S;
S.push(1);
while (!S.empty()) {
    cout << S.top() << endl;
    S.pop();
}
5.queue
queue<int> q;
q.push(1);
while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
}
6.���ȶ���
priority_queue<int> q;
priority_queue ģ����������ģ���������һ����Ԫ�����ͣ��ڶ����������ͣ��������ǱȽ����ӡ�
priority_queue<int, vector<int>, greater<int> > q;
���к�����������ʡ�ԣ�Ĭ������Ϊvector��Ĭ������Ϊless����С����ǰ�ţ���������ţ�����ʱ����β��Ԫ�س��ӣ���
priority_queue<int> q1;
priority_queue< pair<int, int> > q2; // ע��������������֮��һ��Ҫ���ո�
rr q3; //����С���ȳ���
struct Node{
    int x, y;
    Node(int a = 0, int b= 0):x(a), y(b) {}
};
bool operator < (const Node& a, const Node& b ){
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}
priority_queue<Node> q;

7.make_pair

8.string
string s;
s.empty();
s.size();
s.c_str();//����char*���͵��ַ���
s.append("abc");//�ַ���β��׷��
s = s + "abc";
==,!=,<,<=,>,>=  �ַ����Ƚϣ������ַ����̵��볤��ǰ��ƥ�䣬�̵�С�ڳ���
s.substr(i,j);��ȡs���д�i��j���Ӵ�
s.replace(3,3,"good");�ӵ����������������滻Ϊgood
reverse(s.begin(),s.end());  ���������������ַ�����ת����
9.list
list<int> a;
a.push_back(1);
����resize(n)��list�ĳ��ȸ�Ϊֻ����n��Ԫ�أ�������Ԫ�ؽ���ɾ�������n��listԭ���ĳ��ȳ�����ôĬ�ϳ����Ĳ���Ԫ����Ϊ0��Ҳ������resize(n, m)�ķ�ʽ�������Ĳ��ָ�ֵΪm��
ʹ��list�ĳ�Ա����push_back��push_front����һ��Ԫ�ص�list�С�����push_back()�Ǵ�list��ĩ�˲��룬��push_front()�Ǵ�list��ͷ�����롣
ͨ��front()���Ի��list�����е�ͷ��Ԫ�أ�ͨ��back()���Ի��list���������һ��Ԫ�ء�
ʹ��pop_back()����ɾ��β����һ��Ԫ�أ�pop_front()����ɾ��ͷ����һ��Ԫ�ء�
swap(a,b);//������������
reverse(b.begin(),b.end());//����
a.splice(a.begin(), b);//��b�ϲ���a��
a.merge(b)//merge�ϲ��ǻ��Զ�����ġ����ý�����b��Ϊ�գ�a��Ԫ�ذ���ԭ��a��b��Ԫ�ء�
a.insert(a.begin(),100);  //��a�Ŀ�ʼλ�ã���ͷ��������100
a.erase(a.begin());  //��a�ĵ�һ��Ԫ��ɾ��
a.remove(7);//ɾ��a��ֵΪ7��Ԫ��
10.dequeue
push_front();
push_back();
pop_front();
pop_back();
erase();insert();

11.unique
sort(a,a+n);
n = unique(a,a+n) - a;//�ؼ���һ��
