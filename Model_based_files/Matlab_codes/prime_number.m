while (1) 
x = input('enter the number you want to check   ')
flag = 0;
if x <= 1 
    disp('not prime number')
else 
    for i = 2:x/2
        if mod(x,i) ==0 
           disp('not prime number')
           flag =1;
        end
    end
end 
if flag ==1
        disp(' prime number')
end 


end 
    
