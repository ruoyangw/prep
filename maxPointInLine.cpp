    struct Line{
        bool vertical;
        double a,b;
    };
    int maxPoints(vector<Point> &points) {
        if(points.size()<=1)
        return points.size();
        vector<Line> lines;
        Line line;
        int result=0;
        int count;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                count=0;
                line=constructLine(points[i],points[j]);
                for(int q=0;q<points.size();q++){
                    if(!line.vertical){
                    if( abs(points[q].y-(points[q].x*line.a+line.b))<=0.01){
                        count++;
                        }
                    }
                    else{
                        if(points[q].x==line.a)
                        count++;
                    }
                }  
                if(count>result) result=count;
            }
        }
        return result;
    }
    Line constructLine(Point a,Point b){
        Line newline;
        if(a.x!=b.x){
        newline.a=((a.y-b.y)*1.0)/((a.x-b.x)*1.0);
        newline.b=a.y-newline.a*a.x;
        newline.vertical=false;
        }else{
        newline.vertical=true;
        newline.a=a.x;
        }
        return newline;
    }