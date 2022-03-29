/*头文件*/    
#include <stdlib.h>
    #include <stdio.h>
    #include <conio.h>
    #include <string.h>
/*宏定义*/ 
    #define MAXIMUS 15 //定义棋盘大小
/*全局变量*/ 
int p[MAXIMUS][MAXIMUS];//存储对局信息
int Cx,Cy;//当前光标位置
int Now;//当前走子的玩家，1代表黑，2代表白
/*函数声明*/ 
void Auto(int p[MAXIMUS][MAXIMUS],int *k,int *l);
int AICheck(int Cx,int Cy,int now);
int Scoring(int w,int x,int y,int z);
int Statistics(int w,int x,int y,int z,int num);
int Compare(int k,int l);
int Judge(int a[]);
int standard(int a[10]);

int AliveTwo[4][10] = {2,2,0,0,1,1,0,2,2,2, // 1
						   2,2,0,1,1,0,2,2,2,2,
						   2,2,0,1,0,1,0,2,2,2,
						   2,0,1,1,0,0,2,2,2,2
						  };
	int AliveThree[2][10]={2,0,1,1,1,0,2,2,2,2, // 2
						   2,2,0,1,1,1,0,2,2,2
						  };		 
	int DangeFour[3][10]= {2,2,1,1,1,1,2,2,2,2, // 3
						   2,2,2,1,1,1,1,2,2,2,
						   2,1,1,1,1,2,2,2,2,2
						  };
	int AsleepTwo[5][10]= {2,-1,0,0,1,1,-1,2,2,2, // 4
						   2,0,0,0,1,1,-1,2,2,2,
						   2,2,2,0,0,1,1,-1,2,2,
						   2,0,0,1,1,-1,2,2,2,2,
						   2,0,1,1,0,-1,2,2,2,2
						  };
	int AsleepThree[10][10]={2,0,1,1,1,-1,2,2,2,2, // 5
						   2,1,1,0,1,-1,2,2,2,2,
						   2,1,1,1,0,-1,2,2,2,2,
						   2,1,0,1,1,-1,2,2,2,2,
						   2,2,0,1,1,1,-1,2,2,2,
						   2,2,1,0,1,1,2,2,2,2,
						   2,2,1,1,0,1,-1,2,2,2,
						   2,2,2,0,1,1,1,-1,2,2,
						   2,2,2,2,0,1,1,1,-1,2,
						   2,2,2,2,2,0,1,1,1,-1
						  };
	int OnlyOne[3][10] = {2,2,2,2,1,2,2,2,2,2, // 6
						  0,0,0,0,1,0,0,0,0,0,
						  0,0,0,0,-1,0,0,0,0,0
						  
						  };
	int OnlyTwo[1][10] = {0,0,0,1,0,0,0,0,0,0 // 7
						  
						 };

void Auto(int p[MAXIMUS][MAXIMUS],int *k,int *l){
    	int q[15][15]={};
    	int m=7;
    	int n=7;
    	int MAX=0;
    	for(int i = 0; i < MAXIMUS; i++){
			for(int j = 0; j < MAXIMUS; j ++){
				if(p[i][j] != 0)
					continue;
				q[i][j]=AICheck(i,j,Now);
				if(q[i][j]>MAX){
					m = i;
					n = j;
					MAX=q[i][j];
				}
				
			}
		}
	
    	*k=m;
	*l=n;
	}

int AICheck(int Cx,int Cy,int now){		//  检测该位置八个方向上的棋子并统计该点分数 
    	
		int w=0,x=0,y=0,z=0,i; //记录横竖正斜反斜四个方向上属于哪类情况 
    /////////////////////////////////////////////////////////////////
    int W[10]={};
	for(i=1;i<=5;i++){   //向下检查
//		if(i==1)
//		now	== p[Cx][Cy+i];
		if(Cy+i<MAXIMUS&&p[Cx][Cy+i]==now){
			W[5-i]=1;
		}else if(Cy+i<MAXIMUS&&p[Cx][Cy+i]==0){
			W[5-i]=0;
		}else if(Cy+i<MAXIMUS&&p[Cx][Cy+i]==(3-now)){
            W[5-i]=-1;
        }
	}
    for(i=1;i<=5;i++){	//向上检查
        if(Cy-i>0&&p[Cx][Cy-i]==now)
            W[4+i]=1;
        else if(Cy-i>0&&p[Cx][Cy-i]==0){
        	W[4+i]=0;
		}else if(Cy-i>0&&p[Cx][Cy-i]==(3-now)){
            W[4+i]=-1;
        }
	}
    w = Judge(W);
    standard(W);
	w = Judge(W);
	
	/////////////////////////////////////////////////////////////////
	
	int X[10]={};
	for(i=1;i<=5;i++){   //向右检查
//		if(i==1)
//		now	== p[Cx+i][Cy];
		if(Cx+i<MAXIMUS&&p[Cx+i][Cy]==now){
			X[5-i]=1;
		}else if(Cx+i<MAXIMUS&&p[Cx+i][Cy]==0){
			X[5-i]=0;
		}else if(Cx+i<MAXIMUS&&p[Cx+i][Cy]==(3-now)){
            X[5-i]=-1;
        }
	}
    for(i=1;i<=5;i++){	//向左检查
        if(Cx-i>0&&p[Cx-i][Cy]==now)
            X[4+i]=1;
        else if(Cx-i>0&&p[Cx-i][Cy]==0){
        	X[4+i]=0;
		}else if(Cx-i>0&&p[Cx-i][Cy]==(3-now)){
            X[4+i]=-1;
        }
	}
    x = Judge(X);
    standard(X);
	x = Judge(X);
	
	/////////////////////////////////////////////////////////////////
	
	int Y[10]={};
	for(i=1;i<=5;i++){   //向右下检查
//		if(i==1)
//		now	== p[Cx+i][Cy+i];
		if(Cx+i<MAXIMUS&&Cy+i<MAXIMUS&&p[Cx+i][Cy+i]==now){
			Y[5-i]=1;
		}else if(Cx+i<MAXIMUS&&Cy+i<MAXIMUS&&p[Cx+i][Cy+i]==0){
			Y[5-i]=0;
		}else if(Cx+i<MAXIMUS&&Cy+i<MAXIMUS&&p[Cx+i][Cy+i]==(3-now)){
            Y[5-i]=-1;
        }
	}
    for(i=1;i<=5;i++){	//向左上检查
        if(Cx-i>0&&Cy-i>0&&p[Cx-i][Cy-i]==now)
            Y[4+i]=1;
        else if(Cx-i>0&&Cy-i>0&&p[Cx-i][Cy-i]==0){
        	Y[4+i]=0;
		}else if(Cx-i>0&&Cy-i>0&&p[Cx-i][Cy-i]==(3-now)){
            Y[4+i]=-1;
        }
	}
    y = Judge(Y);
    standard(Y);
	y = Judge(Y);
	
	/////////////////////////////////////////////////////////////////
	
	int Z[10]={};
	for(i=1;i<=5;i++){   //向右上检查
//		if(i==1)
//		now	== p[Cx+i][Cy-i];
		if(Cx+i<MAXIMUS&&Cy-i>0&&p[Cx+i][Cy-i]==now){
			Z[5-i]=1;
		}else if(Cx+i<MAXIMUS&&Cy-i>0&&p[Cx+i][Cy-i]==0){
			Z[5-i]=0;
		}else if(Cx+i<MAXIMUS&&Cy-i>0&&p[Cx+i][Cy-i]==(3-now)){
            Z[5-i]=-1;
        }
	}
    for(i=1;i<=5;i++){	//向左下检查 
        if(Cx-i>0&&Cy+i<MAXIMUS&&p[Cx-i][Cy+i]==now)
            Z[4+i]=1;
        else if(Cx-i>0&&Cy+i<MAXIMUS&&p[Cx-i][Cy+i]==0){
        	Z[4+i]=0;
		}else if(Cx-i>0&&Cy+i<MAXIMUS&&p[Cx-i][Cy+i]==(3-now)){
            Z[4+i]=-1;
        }
	}
  	z = Judge(Z);
  	standard(Z);
	z = Judge(Z);
	
	return Scoring(w,x,y,z);
	}

int Scoring(int w,int x,int y,int z){
    	int sum=0;
    	if(w==3 || x==3 || y==3 || z==3 ){
    		return 1000;
		}
		if(w==2 || x==2 || y==2 || z==2 ){
			sum+=500;
		}
		if(Statistics(w,x,y,z,1)==1){
			sum+=7;
		}else if(Statistics(w,x,y,z,1)>1){
			sum+=30;
		}
		if(Statistics(w,x,y,z,5)==1){
			sum+=7;
		}else if(Statistics(w,x,y,z,5)>1){
			sum+=30;
		}
		sum+=(Statistics(w,x,y,z,4));
		sum+=(Statistics(w,x,y,z,7));
		sum+=(2 * Statistics(w,x,y,z,6));
		
		
		return sum;
	}
    
    int Statistics(int w,int x,int y,int z,int num){
    	int sum=0;
    	if(w==num) sum++;
    	if(x==num) sum++;
    	if(y==num) sum++;
    	if(z==num) sum++;
    	return sum;
	}
    
    int Compare(int k,int l){	// 比较 
    	if(l==2){
    		return 1;
		}else if(k==l){
			return 1;
		}
		return 0;
	}
    
    int standard(int a[10]){
    	for(int i = 0; i < 10 ; i ++ ){
    		if(a[i]==1){
    			a[i]=-1;
			}else if(a[i]==-1){
				a[i]=1;
			}
		}
	}
    
    int Judge(int a[10]){		// 判断哪类情况 
    	
    	for(int i = 0; i < 4; i ++){ 
    		for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[j],AliveTwo[i][j])==0)
    				break;
    			if(j==9)
    				return 1;
			}
			for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[9-j],AliveTwo[i][j])==0)
    				break;
    			if(j==9)
    				return 1;
			}
		}
		
		for(int i = 0; i < 2; i ++){ 
    		for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[j],AliveThree[i][j])==0)
    				break;
    			if(j==9)
    				return 2;
			}
			for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[9-j],AliveThree[i][j])==0)
    				break;
    			if(j==9)
    				return 2;
			}
		}
		
		for(int i = 0; i < 3; i ++){ 
    		for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[j],DangeFour[i][j])==0)
    				break;
    			if(j==9)
    				return 3;
			}
			for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[9-j],DangeFour[i][j])==0)
    				break;
    			if(j==9)
    				return 3;
			}
		}
		
		for(int i = 0; i < 5; i ++){ 
    		for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[j],AsleepTwo[i][j])==0)
    				break;
    			if(j==9)
    				return 4;
			}
			for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[9-j],AsleepTwo[i][j])==0)
    				break;
    			if(j==9)
    				return 4;
			}
		}
		
		for(int i = 0; i < 10; i ++){ 
    		for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[j],AsleepThree[i][j])==0)
    				break;
    			if(j==9)
    				return 5;
			}
			for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[9-j],AsleepThree[i][j])==0)
    				break;
    			if(j==9)
    				return 5;
			}
		}
		
		for(int i = 0; i < 3; i ++){ 
    		for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[j],OnlyOne[i][j])==0)
    				break;
    			if(j==9)
    				return 6;
			}
			for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[9-j],OnlyOne[i][j])==0)
    				break;
    			if(j==9)
    				return 6;
			}
		}
		
		for(int i = 0; i < 1; i ++){ 
    		for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[j],OnlyTwo[i][j])==0)
    				break;
    			if(j==9)
    				return 7;
			}
			for(int j = 0; j < 10; j ++){ 
    			if(Compare(a[9-j],OnlyTwo[i][j])==0)
    				break;
    			if(j==9)
    				return 7;
			}
		}
		
		
		return 0;
	}
