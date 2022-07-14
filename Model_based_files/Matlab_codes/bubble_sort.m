function y = bubble_sort(x)

n = length(x);

if x <2 
    y =x; 
    return;
end

for i = 1: n-1
    if x(i) > x(1+1)
        temp =  x(i) ;
        x(i) = x(i+1);
        x(i+1) = temp;
    end

end
y = bubble_sort(x(1 : n-1));

y = [y x(n)]
end