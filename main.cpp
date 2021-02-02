#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct Tacka{
    double x;
    double y;

    Tacka(double a=0., double b=0. ) : x(a), y(b) { }

    double dist(Tacka t) const {
        return sqrt((t.x - x)*(t.x - x) + (t.y - y)*(t.y - y));
    }

};

double obim (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double a, b, c;
    a=t1.dist(t2);
    b=t2.dist(t3);
    c=t3.dist(t1);
    return a + b + c;
}

double povrsina (const Tacka &t1, const Tacka &t2, const Tacka &t3) {

    double a,b,c,s;
    a=t1.dist(t2);
    b=t2.dist(t3);
    c=t3.dist(t1);
    s=obim(a,b,c)/2.;
    return sqrt(abs(s*(s-a)*(s-b)*(s-c)));

}
bool provera (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double a,b,c;
    a= (t2.x - t1.x)/(t3.x - t1.x);
    b= (t2.y - t1.y)/(t3.y - t1.y);
    return c = abs(a - b) == '0.';
    //if(c==0) return cout <<"Prave leze na istoj pravoj. " << endl;

}
int main(){
    char odg;

    cout << "Program koji ispituje osobine trougla. " << endl;
    do{
        char izbor;
        Tacka t1, t2, t3;


        cout << "Izaberite opciju: " << endl;
        cout << "a.Unesi trougao." << endl;
        cout << "b.Udaljenost tacaka od koordinatnog pocetka." << endl;
        cout << "Izbor : ";
        cin >> izbor;
        switch(izbor){
            case 'a':
                cout << "Unesite koordinatu x tacke T1: " << endl;
                cin >> t1.x;
                cout << "Unesite koordinatu y tacke T1: " << endl;
                cin >> t1.y;
                cout << "Unesite koordinatu x tacke T2: " << endl;
                cin >> t2.x;
                cout << "Unesite koordinatu y tacke T2: " << endl;
                cin >> t2.y;
                cout << "Unesite koordinatu x tacke T3: " << endl;
                cin >> t3.x;
                cout << "Unesite koordinatu y tacke T3: " << endl;
                cin >> t3.y;

                if(provera(t1,t2,t3)){
                    cout << "Tacke leze na istoj pravoj." << endl;
                }else{
                cout << "Trougao: T1(" << t1.x << "," << t1.y << ") "
                     << "T2(" << t2.x << "," << t2.y << ") "
                     << "T3(" << t3.x << "," << t3.y << ") " << endl;
                cout << "Povrsina trougla je: " << povrsina(t1, t2, t3) << endl;
                cout << "Obim trougla je: " << obim(t1, t2, t3) << endl;
                break;
                }
            case 'b':{
                int n;
                Tacka kop; // podrazumevano, jer je konstruktor na podrazumevanim vrednostima 0,0
                cout << "Unesite broj tacaka:" << endl;
                cin >> n;
                vector <Tacka> niz(n);

                for(auto i=0; i < n-1; ++i){
                    cout << "Unesite koordinatu x tacke T " << i+1 << ": " << endl;
                    cin >> niz[i].x;
                    cout << "Unesite koordinatu y tacke T " << i+1 << ": " << endl;
                    cin >> niz[i].y;
                    cout << "Rastojanje od koordinatnog pocetka je : " << kop.dist(niz[i]) << endl;
                    }
                }
                break;
                default:
                    cout << "Uneli ste nepostojecu opciju. Pokusajte ponovo." << endl;
        }
        cout << "Da li zelite ponovo da uneste tacke? [d/n]" << endl;
        cin >> odg;
    }while(odg =='d' || odg == 'D');
    cout << "Kraj programa." << endl;
    return 0;
}
