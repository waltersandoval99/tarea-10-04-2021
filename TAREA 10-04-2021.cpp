#include <mysql.h>

#include <iostream>



using namespace std;

int q_estado;

int main(){

	MYSQL* conectar;

	conectar = mysql_init(0);

	conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empres@123", "db_empresa", 3306, NULL, 0);

	if (conectar) {

		string puesto;

		cout << "Ingrese Puesto:";

		cin >> puesto;

		string insert = "insert into puestos(puesto) values('"+ puesto +"')";

		const char* i = insert.c_str();

		q_estado = mysql_query(conectar, i);

		if (!q_estado) {

			cout << "Ingreso Exitoso de la Informacion" << endl;

		}

		else {

			cout << " --- Error al Ingresar ---" << endl;

		}

	}

	else {

		cout << "Error en la Conexion" << endl;

	}

	system("pause");

	return 0;

}
