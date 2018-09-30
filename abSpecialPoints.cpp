usng namespace std;
vector<long long int> vec[300001];
long long int visited[300001]={0};
long long int queue[300001],rear,front;
void bfs(long long int v)
{
	long long int i,j,l=vec[v].size();
	for(i=0;i<l;i++)
	{
		if(visited[vec[v][i]]==0)
		{
			queue[rear++]=vec[v][i];
			visited[vec[v][i]]=1;
		}
	}
	if(front==rear-1)
		return;
	bfs(queue[++front]);
}
int main()
{
	long long int n,m,a,b,i,j,u,v;
	cin>>n>>m>>a>>b;
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			queue[0]=0;
			front=0;
			rear=1;
			bfs(i);
		}
		
	}
	return 0;
}