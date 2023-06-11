#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
using namespace std;
struct Auto
{
    string patente, marca, modelo, color, anio, disponible,estado;
}autos[10];
struct Personas
{
    string nombre, apellido, direccion, telefono, correo, dni;
}clientes[10];
struct Alquiler
{
    Auto autoa;
    Personas personasa;
    string fecha;
}al[10];
int np=0, na=0, nalq=0;
//gotoxy
void gotoxy(int x, int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Menus
void mostrarMenu();
void menuAlquiler();
void menuClientes();
void menuAutos();
//Clientes
void altaClientes(Personas cli[], int& np);
void bajaClientes(Personas cli[], int& np);
void listarClientes(Personas cli[], int& np);
void cargarClientesArchivo(Personas cli[], int& np);
void guardarClientesArchivo(Personas cli[], int& np);
void modificarClientes(Personas cli[], int&np);
//Autos
void altaAutos(Auto au[], int& na);
void bajaAutos(Auto au[], int& na);
void listarAutos(Auto aut[], int& na);
void cargarAutosArchivo(Auto aut[], int& na);
void guardarAutosArchivo(Auto aut[], int& na);
void modificarAutos(Auto aut[], int& na);
//Alquiler
void altaAlquiler(Alquiler al[], int& nalq, Personas cli[], int& np, Auto aut[], int& na);
int main(){
    cout<<"Bienvenidos al programa de alquiler de autos"<<endl;
    system("pause");
    system("cls");
    mostrarMenu();
    return 0;
}
void mostrarMenu(){
    cargarAutosArchivo(autos, na);
    cargarClientesArchivo(clientes, np);
    int op;
    do
    {
        gotoxy(20,1);cout<<"#######################################################################";
        gotoxy(20,2);cout<<"#";gotoxy(90,2);cout<<"#";
        gotoxy(20,3);cout<<"#";gotoxy(90,3);cout<<"#";
        gotoxy(20,4);cout<<"#";gotoxy(90,4);cout<<"#";
        gotoxy(20,5);cout<<"#";gotoxy(45,5);cout<<"----------MENU----------";gotoxy(90,5);cout<<"#";
        gotoxy(20,6);cout<<"#";gotoxy(90,6);cout<<"#";
        gotoxy(20,7);cout<<"#";gotoxy(45,7);cout<<"[1]---> Alquiler";gotoxy(90,7);cout<<"#";
        gotoxy(20,8);cout<<"#";gotoxy(90,8);cout<<"#";
        gotoxy(20,9);cout<<"#";gotoxy(45,9);cout<<"[2]---> Clientes"<<endl;gotoxy(90,9);cout<<"#";
        gotoxy(20,10);cout<<"#";gotoxy(90,10);cout<<"#";
        gotoxy(20,11);cout<<"#";gotoxy(45,11);cout<<"[3]---> Autos"<<endl;gotoxy(90,11);cout<<"#";
        gotoxy(20,12);cout<<"#";gotoxy(90,12);cout<<"#";
        gotoxy(20,13);cout<<"#";gotoxy(45,13);cout<<"[4]---> Salir"<<endl;gotoxy(90,13);cout<<"#";
        gotoxy(20,14);cout<<"#";gotoxy(90,14);cout<<"#";
        gotoxy(20,15);cout<<"#";gotoxy(45,15);cout<<"Ingrese una opcion: ";gotoxy(90,15);cout<<"#";
        gotoxy(20,16);cout<<"#";gotoxy(90,16);cout<<"#";
        gotoxy(20,18);cout<<"#";gotoxy(90,18);cout<<"#";
        gotoxy(20,19);cout<<"#";gotoxy(45,19);cout<<"-----------------------"<<endl;gotoxy(90,19);cout<<"#";
        gotoxy(20,20);cout<<"#";gotoxy(90,20);cout<<"#";
        gotoxy(20,21);cout<<"#";gotoxy(90,21);cout<<"#";
        gotoxy(20,22);cout<<"#";gotoxy(90,22);cout<<"#";
        gotoxy(20,23);cout<<"#######################################################################";
        gotoxy(20, 17);cout<<"#";gotoxy(90,17);cout<<"#";
        gotoxy(47,17);cin>>op;
        system("cls");
        switch(op)
        {
            case 1:
                menuAlquiler();
                break;
            case 2:
                menuClientes();
                break;
            case 3:
                menuAutos();
                break;
            case 4:
                gotoxy(20,11);cout<<"Saliendo gracias por usar el Software VroomVroom";
                system("pause");
                system("cls");
                exit(1);
            default:
                cout<<"Opcion ingresada es incorrecta vuelva a ingresar"<<endl;
                system("pause");
                system("cls");
                break;
        }
    } while (op!=4);
}
void menuAlquiler(){
    int op;
    do
    {
        gotoxy(20,1);cout<<"#######################################################################";
        gotoxy(20,2);cout<<"#";gotoxy(90,2);cout<<"#";
        gotoxy(20,3);cout<<"#";gotoxy(90,3);cout<<"#";
        gotoxy(20,4);cout<<"#";gotoxy(90,4);cout<<"#";
        gotoxy(20,5);cout<<"#";gotoxy(45,5);cout<<"----------MENU----------";gotoxy(90,5);cout<<"#";
        gotoxy(20,6);cout<<"#";gotoxy(90,6);cout<<"#";
        gotoxy(20,7);cout<<"#";gotoxy(45,7);cout<<"[1]---> Agregar Alquiler";gotoxy(90,7);cout<<"#";
        gotoxy(20,8);cout<<"#";gotoxy(90,8);cout<<"#";
        gotoxy(20,9);cout<<"#";gotoxy(45,9);cout<<"[2]---> ELiminar Alquiler"<<endl;gotoxy(90,9);cout<<"#";
        gotoxy(20,10);cout<<"#";gotoxy(90,10);cout<<"#";
        gotoxy(20,11);cout<<"#";gotoxy(45,11);cout<<"[3]---> Modificar Alquiler"<<endl;gotoxy(90,11);cout<<"#";
        gotoxy(20,12);cout<<"#";gotoxy(90,12);cout<<"#";
        gotoxy(20,13);cout<<"#";gotoxy(45,13);cout<<"[4]---> Volver al Menu Principal"<<endl;gotoxy(90,13);cout<<"#";
        gotoxy(20,14);cout<<"#";gotoxy(90,14);cout<<"#";
        gotoxy(20,15);cout<<"#";gotoxy(45,15);cout<<"Ingrese una opcion: ";gotoxy(90,15);cout<<"#";
        gotoxy(20,16);cout<<"#";gotoxy(90,16);cout<<"#";
        gotoxy(20,18);cout<<"#";gotoxy(90,18);cout<<"#";
        gotoxy(20,19);cout<<"#";gotoxy(45,19);cout<<"-----------------------"<<endl;gotoxy(90,19);cout<<"#";
        gotoxy(20,20);cout<<"#";gotoxy(90,20);cout<<"#";
        gotoxy(20,21);cout<<"#";gotoxy(90,21);cout<<"#";
        gotoxy(20,22);cout<<"#";gotoxy(90,22);cout<<"#";
        gotoxy(20,23);cout<<"#######################################################################";
        gotoxy(20, 17);cout<<"#";gotoxy(90,17);cout<<"#";
        gotoxy(47,17);cin>>op;
        system("cls");
        switch (op)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout<<"Volviendo al Menu Principal..."<<endl;
                system("pause");
                system("cls");
                mostrarMenu();
                break;
            default:
                cout<<"Opcion ingresada es incorrecta vuelva a ingresar"<<endl;
                system("pause");
                system("cls");
                break;
        }
    } while (op!=4);
}
void menuClientes(){
    int op;
    do
    {
        cout<<"----------MENU Clientes----------"<<endl;
        cout<<"[1]---> Alta Clientes"<<endl;
        cout<<"[2]---> Baja Clientes"<<endl;
        cout<<"[3]---> Modificar Clientes"<<endl;
        cout<<"[4]---> Listar Clientes"<<endl;
        cout<<"[5]---> Volver al Menu Principal"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        system("cls");
        switch (op)
        {
            case 1:
                altaClientes(clientes,np);
                guardarClientesArchivo(clientes,np);
                break;
            case 2:
                bajaClientes(clientes,np);
                guardarClientesArchivo(clientes,np);
                break;
            case 3:
                modificarClientes(clientes, np);
                guardarClientesArchivo(clientes,np);
                break;
            case 4:
                listarClientes(clientes, na);
                break;
            case 5:
                cout<<"Volviendo al Menu Principal..."<<endl;
                system("pause");
                system("cls");
                mostrarMenu();
                break;
            default:
                break;
        }
    } while (op!=5);
}
void menuAutos(){
    int op;
    do
    {
        cout<<"----------MENU Autos----------"<<endl;
        cout<<"[1]---> Alta Autos"<<endl;
        cout<<"[2]---> Baja Autos"<<endl;
        cout<<"[3]---> Modificar Autos"<<endl;
        cout<<"[4]---> Listar Autos"<<endl;
        cout<<"[5]---> Volver al Menu Principal"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        system("cls");
        switch (op)
        {
            case 1:
                altaAutos(autos,na);
                guardarAutosArchivo(autos,na);
                break;
            case 2:
                bajaAutos(autos,na);
                guardarAutosArchivo(autos,na);
            case 3:
                modificarAutos(autos, na);
                guardarAutosArchivo(autos, na);
                break;
            case 4:
                listarAutos(autos, na);
            case 5:
                cout<<"Volviendo al Menu Principal..."<<endl;
                system("pause");
                system("cls");
                mostrarMenu();
                break;
            default:
                cout<<"Opcion ingresada es incorrecta vuelva a ingresar"<<endl;
                system("pause");
                system("cls");
                break;
        }
    } while (op!=5);
}
//Funciones Clientes
void altaClientes(Personas cli[], int& np){
    Personas ncli;
    
    cout<<"Ingrese los datos del cliente"<<endl;
    fflush(stdin);
    cout<<"Apellido: "<<endl;
    cin.ignore();
    getline(cin,ncli.apellido);
    fflush(stdin);
    cout<<"Nombre: "<<endl;
    fflush(stdin);
    getline(cin,ncli.nombre);
    fflush(stdin);    
    cout<<"Dni: "<<endl;
    fflush(stdin);
    cin>>ncli.dni;
    cin.ignore();
    cout<<"Direccion: "<<endl;
    fflush(stdin);
    getline(cin,ncli.direccion);
    fflush(stdin);
    cout<<"Telefono: "<<endl;
    fflush(stdin);
    getline(cin,ncli.telefono);
    fflush(stdin);
    cout<<"Correo: "<<endl;
    fflush(stdin);
    getline(cin,ncli.correo);
    fflush(stdin);
    system("clear");
    cout<<"Persona cargada correctamente. "<<endl;
    cli[np]=ncli;
    np++;
}
void bajaClientes(Personas cli[], int& np){
    string dni;
    cout<<"Ingrese el DNI de la persona a dar de baja"<<endl;
    cin>>dni;
    bool b=false;
    for (int i = 0; i < np; i++)
    {
        if(cli[i].dni==dni){
            b=true;
            for (int j = i; j < np-1; j++)
            {
                cli[i]=cli[j+1];
            }
            np--;
            cout<<"Personas eliminada correctamente"<<endl;
            break;
        }
    }
}
void listarClientes(Personas cli[], int& np){
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|   Dni   |   Nombre   |   Apellido   |   Direccion   |   Telefono   |   Correo   |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < np; i++) {
        printf("|%-11s|%-11s|%-12s|%-11s|%-9s|%-17s|\n",cli[i].dni.c_str(), cli[i].nombre.c_str(), cli[i].apellido.c_str(), cli[i].direccion.c_str(), cli[i].telefono.c_str(), cli[i].correo.c_str());
    }
    cout << "-------------------------------------------------------------------------------" << endl;
    
}
void modificarClientes(Personas cli[], int& np){
    string d,a,n,dir,t,c;
    int campo;
    cout<<"Ingrese el documento de la persona a modifica: ";
    fflush(stdin);
    getline(cin,d);
    bool encontrado=false;
    for(int i=0;i<np;i++){
        if(cli[i].dni==d){
            encontrado=true;
            cout<<"Persona encontrada indique que campo quiere modificiar "<<endl;
            do
            {
                cout<<"[1]---> Apellido"<<endl;
                cout<<"[2]---> Nombre"<<endl;
                cout<<"[3]---> Direccion"<<endl;
                cout<<"[4]---> Telefono"<<endl;
                cout<<"[5]---> Correo"<<endl;
                cout<<"[6]---> Cancelar"<<endl;
                cin>>campo;
                switch (campo)
                {
                case 1:
                    cout<<"Ingrese el nuevo apellido: "<<endl;
                    fflush(stdin);
                    getline(cin,a);
                    cli[i].apellido=a;
                    break;
                case 2:
                    cout<<"Ingrese el nuevo nombre: "<<endl;
                    fflush(stdin);
                    getline(cin,n);
                    cli[i].nombre=n;
                    break;
                case 3:
                    cout<<"Ingrese la nueva direccion: "<<endl;
                    fflush(stdin);
                    getline(cin,dir);
                    cli[i].direccion=dir;
                    break;
                case 4:
                    cout<<"Ingrese el nuevo telefono: "<<endl;
                    fflush(stdin);
                    getline(cin,t);
                    cli[i].telefono=t;
                    break;
                case 5:
                    cout<<"Ingrese el nuevo correo: "<<endl;
                    fflush(stdin);
                    getline(cin,c);
                    cli[i].correo=c;
                    break;
                case 6:
                    break;
                default:
                    break;
                }
            } while (campo!=6);
            break;
        }
    }
    
    if (!encontrado)
    {
        cout<<"No se encontro a la persona."<<endl;
    }

}
void guardarClientesArchivo(Personas cli[], int&np){
    ofstream archivo("cliente.txt");
    for(int i=0;i<np;i++){
        archivo<<cli[i].dni<<","<<cli[i].nombre<<","<<cli[i].apellido<<","<<cli[i].direccion<<","<<cli[i].telefono<<","<<cli[i].correo<<","<<endl;
    }
    archivo.close();
}
void cargarClientesArchivo(Personas cli[], int&np){
    ifstream archivo("cliente.txt");
    string linea;
    int tam=0;
    while (getline(archivo,linea))
    {
        tam++;
    }
    archivo.close();
    archivo.open("cliente.txt");
    while(getline(archivo,linea)){
        Personas a;
        int pos=0, campo=0;
        string temp;
        while (pos<linea.length())
        {
            if(linea[pos]==','){
                switch (campo)
                {
                    case 0:
                        a.dni=temp;
                        break;
                    case 1:
                        a.nombre=temp;
                        break;
                    case 2:
                        a.apellido=temp;
                        break;
                    case 3:
                        a.direccion=temp;
                        break;
                    case 4:
                        a.telefono=temp;
                        break;
                    case 5:
                        a.correo=temp;
                        break;
                    default:
                        break;
                }
                campo++;
                temp="";
            }
            else{
                temp += linea[pos];
            }
            pos++;
        }
        cli[np]=a;
        np++;
    }
    archivo.close();
}
//Funciones Autos
void listarAutos(Auto aut[], int& na) {
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|   Patente   |   Marca   |   Modelo   |   Color   |   Año   |   Disponible   |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < na; i++) {
        printf("|%-13s|%-11s|%-12s|%-11s|%-9s|%-17s|\n",aut[i].patente.c_str(), aut[i].marca.c_str(), aut[i].modelo.c_str(), aut[i].color.c_str(), aut[i].anio.c_str(), aut[i].disponible.c_str());
    }
    cout << "-------------------------------------------------------------------------------" << endl;
}
void altaAutos(Auto aut[], int& na){
    Auto au;
    int aux;
    cout<<"Ingrese los datos de auto"<<endl;
    cin.ignore();
    cout<<"Patente: "<<endl;
    fflush(stdin);
    getline(cin,au.patente);
    cout<<"Marca: "<<endl;
    fflush(stdin);
    getline(cin,au.marca);
    cout<<"Modelo: "<<endl;
    fflush(stdin);
    getline(cin,au.modelo);
    cout<<"Color: "<<endl;
    fflush(stdin);
    getline(cin,au.color);
    cout<<"Anio: "<<endl;
    cin>>au.anio;
    cout<<"Disponibilidad [0: disponible]-[1: no disponible]: "<<endl;
    cin>>aux;
    if (aux==0){
        au.disponible=true;
    }
    else{
        //au.disponible=false;
    }
    aut[na]=au;
    na++;
    
}
void bajaAutos(Auto aut[], int& na){
    string pate;
    cout<<"Ingrese la patente del auto a dar de baja: "<<endl;
    cin.ignore();
    getline(cin,pate);
    bool b=false;
    for (int i = 0; i < na; i++)
    {
        if(aut[i].patente==pate){
            b=true;
            for (int j = i; j < na-1; j++)
            {
                aut[j]=aut[j+1];
            }
            na--;
            cout<<"Auto eliminado correctamente."<<endl;
            break;
        }
    }
    
}
void modificarAutos(Auto aut[], int& na){
    string pat,m,mod,c,a,d,e;
    int campo;
    cout<<"Ingrese la patente del auto a modificar"<<endl;
    fflush(stdin);
    getline(cin,pat);
    bool encontrado=false;
    for (int i = 0; i < na; i++)
    {
        if (aut[i].patente==pat)
        {
            encontrado=true;
            cout<<"Auto encontrado indique que campo quiere modificar"<<endl;
            do
            {
                cout<<"[1]---> Marca"<<endl;
                cout<<"[2]---> Modelo"<<endl;
                cout<<"[3]---> Color"<<endl;
                cout<<"[4]---> Año"<<endl;
                cout<<"[5]---> Disponibilidad"<<endl;
                cout<<"[6]---> Estado"<<endl;
                cout<<"[7]---> Cancelar/Salir"<<endl;
                cin>>campo;
                switch (campo)
                {
                case 1:
                    cout<<"Ingrese la nueva marca: "<<endl;
                    fflush(stdin);
                    getline(cin,m);
                    aut[i].marca=m;
                    break;
                case 2:
                    cout<<"Ingrese el nuevo modelo: "<<endl;
                    fflush(stdin);
                    getline(cin,mod);
                    aut[i].modelo=mod;
                    break;
                case 3:
                    cout<<"Ingrese el nuevo color: "<<endl;
                    fflush(stdin);
                    getline(cin,c);
                    aut[i].color=c;
                    break;
                case 4:
                    cout<<"Ingrese el nuevo año: "<<endl;
                    fflush(stdin);
                    getline(cin,a);
                    aut[i].anio=a;
                    break;
                case 5:
                    cout<<"Ingrese la nueva disponibilidad: "<<endl;
                    fflush(stdin);
                    getline(cin,d);
                    aut[i].disponible=d;
                    break;
                case 6:
                    cout<<"Ingrese el nuevo estado: "<<endl;
                    fflush(stdin);
                    getline(cin,e);
                    aut[i].estado=e;
                    break;
                case 7:
                    break;
                default:
                    break;
                }
            } while (campo!=7);
            
        }
        
    }
    
}
void cargarAutosArchivo(Auto aut[], int& na){
    ifstream archivo("autos.txt");
    string linea;
    int tam=0;
    while (getline(archivo,linea))
    {
        tam++;
    }
    archivo.close();
    archivo.open("autos.txt");
    while(getline(archivo,linea)){
        Auto a;
        int pos=0, campo=0;
        string temp;
        while (pos<linea.length())
        {
            if(linea[pos]==','){
                switch (campo)
                {
                    case 0:
                        a.patente=temp;
                        break;
                    case 1:
                        a.marca=temp;
                        break;
                    case 2:
                        a.modelo=temp;
                        break;
                    case 3:
                        a.color=temp;
                        break;
                    case 4:
                        a.anio=temp;
                        break;
                    case 5:
                        a.disponible=temp;
                        break;
                    default:
                        break;
                }
                campo++;
                temp="";
            }
            else{
                temp += linea[pos];
            }
            pos++;
        }
        aut[na]=a;
        na++;
    }
    archivo.close();
    
}
void guardarAutosArchivo(Auto aut[], int& na){
    ofstream archivo("autos.txt");
    for(int i=0;i<na;i++){
        archivo<<aut[i].patente<<","<<aut[i].marca<<","<<aut[i].modelo<<","<<aut[i].color<<","<<aut[i].anio<<","<<aut[i].disponible<<","<<endl;
    }
    archivo.close();
}
//Funciones Alquiler...
void altaAlquiler(Alquiler al[], int& nalq, Personas cli[], int& np, Auto aut[], int& na){
    Alquiler nal;
    
    string dni;
    cout<<"Ingrese el dni de la persona que alquilara"<<endl;
    fflush(stdin);
    getline(cin,dni);
    for (int i = 0; i < np; i++)
    {
        if(cli[i].dni==dni){

        }
    }
}