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
