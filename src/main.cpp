#include <QApplication>
#include "dashboard.h"
#include "appSetup.h"
#include "login.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/assets/MyCloud-logo.png"));
    
    //check if user already exists
    ifstream userData("data/userdata.txt");
    bool newUser=false;
    if(!userData.is_open()){
        newUser=true;
    }
    userData.close();
    if(newUser){
        appSetup setupWizard;
        setupWizard.setWindowTitle("MyCloud Setup");
        if(setupWizard.exec() == QDialog::Accepted){
            Dashboard window;
            window.setWindowTitle("MyCloud Dashboard");
            window.show();
            return app.exec();
        }
     }
     else{
        login loginWizard;
        loginWizard.setWindowTitle("MyCloud Login");
        if(loginWizard.exec() == QDialog::Accepted){
            Dashboard window;
            window.setWindowTitle("MyCloud Dashboard");
            window.show();
            return app.exec();
        }
     }

    return 0;
}
