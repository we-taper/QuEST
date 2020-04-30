/** @file 
 * A demo of QuEST
 *
 * @author Ania Brown
 * @author Tyson Jones
 */

#include <stdio.h>
#include "QuEST.h"

int main (int narg, char *varg[]) {



    /*
     * PREPARE QuEST environment
     * (Required only once per program)
     */

    QuESTEnv env = createQuESTEnv();

    printf("-------------------------------------------------------\n");
    printf("Running QuEST tutorial:\n\t Basic circuit involving a system of 3 qubits.\n");
    printf("-------------------------------------------------------\n");



    /*
     * PREPARE QUBIT SYSTEM
     */

    Qureg qubits = createDensityQureg(1, env);
    initPlusState(qubits);



    /*
     * REPORT SYSTEM AND ENVIRONMENT
     */
    printf("\nThis is our environment:\n");
    reportQuregParams(qubits);
    reportQuESTEnv(env);

    /*
     * STUDY QUANTUM STATE
     */

    printf("\nDensity Matrix Before:\n");
    Complex prob;
    prob = getDensityAmp(qubits, 0, 0);
    printf("Density matrix 0,0 %g + i %g\n", prob.real, prob.imag);
    prob = getDensityAmp(qubits, 0, 1);
    printf("Density matrix 0,1 %g + i %g\n", prob.real, prob.imag);
    prob = getDensityAmp(qubits, 1, 0);
    printf("Density matrix 1,0 %g + i %g\n", prob.real, prob.imag);
    prob = getDensityAmp(qubits, 1, 1);
    printf("Density matrix 0,0 %g + i %g\n", prob.real, prob.imag);


    /*
     * APPLY CIRCUIT
     */   
    mixDepolarising(qubits, 0, 0.3);
    
    /*
     * STUDY QUANTUM STATE
     */

    printf("\nDensity Matrix After:\n");
    prob = getDensityAmp(qubits, 0, 0);
    printf("Density matrix 0,0 %g + i %g\n", prob.real, prob.imag);
    prob = getDensityAmp(qubits, 0, 1);
    printf("Density matrix 0,1 %g + i %g\n", prob.real, prob.imag);
    prob = getDensityAmp(qubits, 1, 0);
    printf("Density matrix 1,0 %g + i %g\n", prob.real, prob.imag);
    prob = getDensityAmp(qubits, 1, 1);
    printf("Density matrix 0,0 %g + i %g\n", prob.real, prob.imag);

    /*
     * FREE MEMORY
     */

    destroyQureg(qubits, env); 

    /*
     * CLOSE QUEST ENVIRONMET
     * (Required once at end of program)
     */
    destroyQuESTEnv(env);
    return 0;
}
