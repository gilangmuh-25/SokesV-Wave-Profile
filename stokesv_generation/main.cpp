#include <iostream>
#include <cmath>
#include <fstream>

float H, L, D, T, step, val, y, teta, Size, k, e, omega, S, B22, B31, B42, B44, B53, B55;
int case_;
const char* File_Name;

void coeff_(){
    //k = 2*(float(22)/7)/L;
    k = 0.143562;
    omega = 2*(float(22)/7)/T;
    S = 1/cosh(2*k*D);
    e = k*H/2;
    B22 = (1/tanh(k*D))*(1+(2*S))/(2*(1-S));
    B31 = -3*(1+(3*S)+(3*pow(S,2))+(2*pow(S,3)))/(8*pow(1-S,3));
    B42 = (1/tanh(k*D))*(6-(26*S)-(182*pow(S,2))-(204*pow(S,3))-(25*pow(S,4))+(26*pow(S,5)))/(6*(3+(2*S))*pow(1-S,4));
    B44 = (1/tanh(k*D))*(24+(92*S)+(122*pow(S,2))+(66*pow(S,3))+(67*pow(S,4))+(34*pow(S,5)))/(24*(3+(2*S))*pow(1-S,4));
    B53 = 9*(132+(17*S)-(2.216*pow(S,2))-(5.897*pow(S,3))-(6.292*pow(S,4))+(2.687*pow(S,5))+(194*pow(S,6))+(467*pow(S,7))+(82*pow(S,8)))/(128*(3+(2*S))*(4+S)*pow(1-S,6));
    B55 = 5*(300+(1.579*S)-(3.176*pow(S,2))-(2.949*pow(S,3))-(1.188*pow(S,4))+(675*pow(S,5))+(1.326*pow(S,6))+(827*pow(S,7))+(130*pow(S,8)))/(384*(3+(2*S))*(4+S)*pow(1-S,6));
}


int main() {
    H = 4; //ketinggian puncak ke puncak
    //L = 43.784; //panjang gelombang
    T = 5.1; //periode
    D = 70; //kedalaman air

    case_ = 1; //1 = posisi konstan. 2 = waktu konstan
    val = 50; // nilai konstanta waktu atau posisi
    Size = 100; //lebar data waktu atau posisi
    step = 0.1; // step waktu atau posisi
    File_Name = "H=295,t=50.csv"; //nama file
    coeff_();

    std::cout << "H = " << H <<"\n";
    std::cout << "L = " << L <<"\n";
    std::cout << "T = " << T <<"\n";
    std::cout << "D = " << D <<"\n";
    std::cout << "k = " << k <<"\n";
    std::cout << "e = " << e <<"\n";
    std::cout << "omega = " << omega <<"\n";
    std::cout << "S = " << S <<"\n";
    std::cout << "B22 = " << B22 <<"\n";
    std::cout << "B31 = " << B31 <<"\n";
    std::cout << "B42 = " << B42 <<"\n";
    std::cout << "B44 = " << B44 <<"\n";
    std::cout << "B53 = " << B53 <<"\n";
    std::cout << "B55 = " << B55 <<"\n";

    std::ofstream myfile(File_Name);

        switch (case_){
            case 1:
            std::cout << "(x)" << "(t)" << " " << "(teta)" << " " << "(y)" << "\n";
            myfile << "(x)" << " " << "(t)" << " " << "(teta)" << " " << "(y)" << "\n";
            for (float t = 0; t <= Size; t+=step) {
                teta = (k*val)-(omega*t);
                y = D+((e*cos(teta))+(pow(e,2)*B22*cos(2*teta))+(pow(e,3)*B31*((cos(teta))-(cos(3*teta))))+(pow(e,4)*((B42*cos(2*teta))+(B44*cos(4*teta))))+(pow(e,5)*((-(B53+B55)*cos(teta))+(B53*cos(3*teta))+(B55*cos(5*teta)))))/k;
                std::cout << val << " " << t << " " << teta << " " << y << "\n";
                myfile << val << " " << t << " " << teta << " " << y << "\n";
                }
            break;

            case 2:
            std::cout << "(x)" << "(t)" << " " << "(teta)" << " " << "(y)" << "\n";
            myfile << "(x)" << " " << "(t)" << " " << "(teta)" << " " << "(y)" << "\n";
            for (float x = 0; x <= Size; x+=step) {
                teta = (k*x)-(omega*val);
                y = D+((e*cos(teta))+(pow(e,2)*B22*cos(2*teta))+(pow(e,3)*B31*((cos(teta))-(cos(3*teta))))+(pow(e,4)*((B42*cos(2*teta))+(B44*cos(4*teta))))+(pow(e,5)*((-(B53+B55)*cos(teta))+(B53*cos(3*teta))+(B55*cos(5*teta)))))/k;
                std::cout << x << " " << val << " " << teta << " " << y << "\n";
                myfile << x << " " << val << " " << teta << " " << y << "\n";
                }
            break;
        }

    return 0;
}
