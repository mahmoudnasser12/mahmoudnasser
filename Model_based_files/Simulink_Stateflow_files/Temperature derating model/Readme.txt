This is a a smiple temperature derating model 
the model consists of 4 parts
1 - signal builder block which has two triggering events signal 
the first event to wake up the stateflow 
the second one to trigger transition between power of and one mode
2 - stateflow block wich contains the logic for the model 
simply the model has 120 degree threshold 
when the temperature is above 120 degree the first fan will work 
then if the temperature is still high and exceeds 150 degree
the second fan will be on 

and there is a state that checks how many fans are working

3 - plant model for the systems 
it takes the number of working fans and based on it
it selects the cooling coefficient

4 - a flag that is being raised according to system temperature with a simple gui

Mahmoud Nasser