#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <vector>
#include <string>


    // FALTA IMPLEMENTAR 
class Asignatura
{
    private:

        std::string nombre;

        // Aqui una lista de atributos
        double alumnos;
        /*
        ..............
        */

    public:
        Asignatura(std::string nombre, double alumnos );
        std::string getNombre();
        double getAlumnos();

};


#endif
