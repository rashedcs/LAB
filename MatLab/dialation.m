s=imread('babu.jpg');
g=im2bw(s);
[m n]=size(g);
b = [0 1 0; 1 1 1 ; 0 1 0]; 
[p q]=size(b);           
temp= zeros(m,n);

for i=1:m
   for j=1:n
      if (g(i,j)==1)    
         for k=1:p
            for l=1:q
              if(b(k,l)==1)
               c=i+k;
               d=j+l;
               temp(c,d)=1;
            end
           end
         end
      end
   end
end

subplot(2,1,1), imshow(g),title('orginal image');
subplot(2,1,2), imshow(temp),title('dialation image');
