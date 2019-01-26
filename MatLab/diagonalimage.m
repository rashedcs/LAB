im = imread('bby.jpg')
subplot(2,1,1)
imshow(im),title('orginal image');

[x,y] = size(im)

for i = 1: x
    for j = 1: y
         if (i == j)
            im(i,j) =255;
      
         elseif (i+j == y+1)
              
                   im(i,j) =255;
              end
       
    end
end

subplot(2,1,2);
imshow(im),title('diagonal mark image')
imshow(im)