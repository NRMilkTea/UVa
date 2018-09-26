#include<iostream>
using namespace std;

int main(){
    int b1,b2,b3,c1,c2,c3,g1,g2,g3;
    while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3){
        int total = b1 + b2 + b3 + c1 + c2 + c3 + g1 + g2 + g3;
        int min = total;
        string ans;
        if(min > total - b1 - c2 - g3){min = total - b1 - c2 - g3; ans = "BCG";}
        if(min > total - b1 - g2 - c3){min = total - b1 - g2 - c3; ans = "BGC";}
        if(min > total - c1 - b2 - g3){min = total - c1 - b2 - g3; ans = "CBG";}
        if(min > total - c1 - g2 - b3){min = total - c1 - g2 - b3; ans = "CGB";}
        if(min > total - g1 - b2 - c3){min = total - g1 - b2 - c3; ans = "GBC";}
        if(min > total - g1 - c2 - b3){min = total - g1 - c2 - b3; ans = "GCB";}
        cout << ans << ' ' << min << endl;
    }
    
    return 0;
}
