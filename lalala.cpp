    #include <fstream>
    #include <set>
    using namespace std;

    set < pair<int,int> > Ship;
    set < pair<int,int> >::iterator it,i,j;
    int N;

    int main() {

        int X,Y;
        ifstream in("sea2.in");
        ofstream out("sea2.out");
        in>>N;

        while(N--) {

            in>>X>>Y;
            it=Ship.upper_bound(make_pair(X,Y));

            if(it!=Ship.end() && it->second>Y)
                out<<"-1\n";
            else {

                if(Ship.size()) {
                    for(i=it;i!=Ship.begin();i=j) {
                        j=i;--j;
                        if(j->second>Y)
                            break;
                        }
                    Ship.erase(i,it);
                    }

                Ship.insert(make_pair(X,Y));
                out<<Ship.size()<<'\n';

                }

        }
        return 0;
    }
