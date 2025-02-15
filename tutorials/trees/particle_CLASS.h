#include<TObject.h>

class particle_CLASS: 

public TObject {

private:
        double position[3]; 
        double energy; 

public:
    particle_CLASS() { }

    void Set_position(double x, double y, double z) {
        position[0] = x; position[1] = y; position[2] = z;        
    }

    void Set_energy(double e) {
        energy = e;
    }

    double * Get_position() { 
        return position; 
    }

    double  Get_energy() {
        return energy; 
    }

    ClassDef(particle_CLASS,1)  
};

