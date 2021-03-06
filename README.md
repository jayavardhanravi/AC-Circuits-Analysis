# AC-Circuits-Analysis
Analysis of steady state AC Circuits using C++ programming

This project shows how we have analysed the steady state AC circuit using
the mesh analysis and by inspection of circuit schematic diagram. And also
solving the mesh equations in C++ programming by using the LAPACK
library functions. We represented the mesh equations in matrix form in
terms of voltage and mesh currents. The voltage and current at various
frequencies are computed with C++ program and plotted different graphs
for the magnitude and phase of both voltage and current with respect to
frequency. By analysis and programming helps us to solve and compare
various parameters with ease and accuracy.

We use the subroutine CGESV in LAPACK library to solve the system of
linear equations. This subroutine uses LU decomposition technique.
The subroutines in LAPACK have a particular naming convention of the
format
P M M AAA
P - Represents the single or double precision.
M M - Represents the type of matrix.
AAA - Represents the type of algorithm implemented.

## Note : 
For mesh analysis and other mathematical computations check the SimpleRC Circuit Frequency Analysis.pdf
 file.
