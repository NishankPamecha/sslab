#include<bits/stdc++.h>
using namespace std;
int hit=0;

int pageFaults(int pages[], int n, int capacity)
{
	
	unordered_set<int> s;

	unordered_map<int, int> indexes;

	
	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
		if (s.size() < capacity)
		{
		    if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				page_faults++;
			}

			indexes[pages[i]] = i;
		}

		else
		{
			if (s.find(pages[i]) == s.end())
			{
			
				int lru = INT_MAX, val;
				for (auto it=s.begin(); it!=s.end(); it++)
				{
					if (indexes[*it] < lru)
					{
						lru = indexes[*it];
						val = *it;
					}
				}

				s.erase(val);

				s.insert(pages[i]);

				page_faults++;
			}
			else hit++;

			indexes[pages[i]] = i;
		}
	}
    return page_faults;
}

int main()
{
	int n;
	cout<<"enter the number of inputs\n";
	cin>>n;
	int input[n];
	cout<<"enter inputs";
	for(int i=0;i<n;i++)
	cin>>input[i];
	int capacity = 3;
	int faults = pageFaults(input, n, capacity);
	cout <<"page faults is "<<faults<<endl;
	cout <<" hits is "<<hit<<endl;
	cout<<"hit ratio is "<<(hit*100)/(hit+faults);
	return 0;
}
