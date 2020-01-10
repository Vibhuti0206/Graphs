#include<bits/stdc++.h>
using namespace std;                        //attach picture to see the output
void printmat(char input[][50])
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<input[i][j];
		}
		cout<<endl;
	}
}
//west,east,south,north
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

//ch is the chracter to be replaced
//color is the character to be added (as a replacement)
void floodfill(char mat[][50];int i;int j;char ch;char color)
{
	//Base case-matrix bounds
	if(i<0 || j<0 || i>=r || j>=c)
	{
		return;
	}
	//figure boundary condition
	if(mat[i][j] != ch)
	{
		return;
	}
	//recursive call
	mat[i][j] = color;
	for(int k=0;k<4;k++)
	{
		floodfill(mat,i+dx[k],j+dy[k],ch,color);
	}
}
int main()
{
	int r,c;
	cin>>r>>c;
	char input[15][50];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>input[i][j];
		}
	}
	printmax(input);
	floodfill(input,8,13,'.','r'); //8,13 are the coordintaes where we give the color initially and thereafter it floods everywhere
	printmax(input);
	return 0;
}
