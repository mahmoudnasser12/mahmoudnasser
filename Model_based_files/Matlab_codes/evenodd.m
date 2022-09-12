x = input('enter your number to check')
if mod(x,2) == 0
    disp ('even number')
else 
    disp('odd number')
end
%generate even and odd numbers to a specific value
y = input('enter the limit')
k =1; % for even
l = 1; % for odd
for i = 1:y
    if mod (i,2) ==0
        even(k) =i;
        k = k+1;
    else 
        odd(l) =i;
        l = l+1;
    end
end
disp ('even numbers are ')
disp(even);
disp ('odd numbers are ')
disp(odd);
