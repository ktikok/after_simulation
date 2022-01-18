void ReadTextFile()

{
//    2  Mean         2.78327e+00   2.21133e-02  -2.57720e-04   5.41908e-02
//    3  Sigma        1.05467e+00   1.47848e-02   1.47848e-02   8.98789e-02
//    2  Mean         4.22999e+00   9.53301e-03  -2.73559e-05  -6.20676e-03
//    3  Sigma        5.13466e-01   7.09625e-03   7.09625e-03   4.81962e-02
//    2  Mean         6.99889e+00   2.84431e-02  -1.54535e-04   7.18742e-04
//    3  Sigma        1.42734e+00   1.85428e-02   1.85428e-02  -3.22046e-02

    string StringValues[8][12];
    double DoubleMS[8][7]={0.0};
    double DoubleMS_Error[8][7]={0.0};

    int flag;
    char flag1;
    int flag3=0;
    int flag4=0;
    int flag5;
    
    int LineNum;

    string line;

    string energy;
    string FileName;
    for (int j=0; j<8; j++) {
        LineNum=0;
        
        if(j==0){
            energy = "110";
        } 
        else if(j==1){
            energy = "90";
        } 
        else if(j==2){
            energy = "70";
        } 
        else if(j==3){
            energy = "50";
        } 
        else if(j==4){
            energy = "30";
        } 
        else if(j==5){
            energy = "20";
        } 
        else if(j==6){
            energy = "10";
        } 
        else{
            energy = "5";
        } 
        FileName = "/data4/tikim/dual-readout/install/0_pion/"+energy+"GeV_pi/"+energy+"GeV_pi_CSS_MS_Error.txt";
        ifstream myfile (FileName);//("/data4/tikim/dual-readout/install/0_pion/10GeV_pi/10GeV_pi_CSS_MS_Error.txt");
        while ( getline (myfile,line) )
        {
          //cout << line << '\n';
            flag=0;
            flag1 = ' ';
            for (int i=0; i<100; i++) {
                if(line[i]!=' ' && flag1==' '){
                    //cout<<"first "<<i<<endl;
                    //cout<<flag<<endl;

                    flag=flag+1;
                    if(flag>2){
                        flag3=i;
                    }
                    //if(flag==4){
                    //    flag4=i;
                    //}
                    //if(flag==5){
                    //    flag5=i;
                    //}                
                }
                if(line[i] == ' ' && flag1 != ' '){
                    //cout<<"second "<<i<<endl;
                    if(flag>2){
                        flag4=i;
                    }                
                }

                if(flag3 !=0 && flag4 != 0){
                    //cout << flag3<<" "<< flag4<<endl;
                    //cout << line.substr(flag3,flag4-flag3) << endl;
                    StringValues[j][LineNum*2+(flag-3)]=line.substr(flag3,flag4-flag3);
                    flag3=0;
                    flag4=0;
                    if(flag==4){
                        break;
                    }
                }
                flag1=line[i];
//  

            }
            LineNum=LineNum+1;
            //break;
        }
        myfile.close();
        
        //break;
    }
    for (int j=0; j<8; j++) {
        for (int i=0; i<6; i++) {
            //cout << StringValues[j][i] << " ";
            stringstream ss(StringValues[j][2*i]);
            ss>>DoubleMS[j][i];
            stringstream ss1(StringValues[j][2*i+1]);
            ss1>>DoubleMS_Error[j][i];
        }
    }
    DoubleMS[0][6]=110;
    DoubleMS_Error[0][6]=110;
    DoubleMS[1][6]=90;
    DoubleMS_Error[1][6]=90;
    DoubleMS[2][6]=70;
    DoubleMS_Error[2][6]=70;
    DoubleMS[3][6]=50;
    DoubleMS_Error[3][6]=50;
    DoubleMS[4][6]=30;
    DoubleMS_Error[4][6]=30;
    DoubleMS[5][6]=20;
    DoubleMS_Error[5][6]=20;
    DoubleMS[6][6]=10;
    DoubleMS_Error[6][6]=10;
    DoubleMS[7][6]=5;
    DoubleMS_Error[7][6]=5;
    //for (int j=0; j<8; j++) {
    //    cout << j<<endl;
    //    for (int i=0; i<7; i++) {
    //        cout << DoubleMS[j][i] << " " << DoubleMS_Error[j][i] << endl;
    //        //DoubleValue[j][i] = stod(StringValues[j][i]);
    //    }
    //    cout << ""<<endl;
    //}
}