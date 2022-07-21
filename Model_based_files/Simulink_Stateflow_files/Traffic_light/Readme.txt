This is a simple traffic light model with simple dashboard
Model contains:
1 - signal builder block which works as clock 
with frq 50 Hz
2 - Triggered Stateflow chart 
which is triggered (sampled) with either failing or rising edge 
3 - simple dashboard 

Fixed solver with Max step size (1e-4)