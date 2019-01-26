im = imread('bby.jpg')

subplot(2,1,1)
imshow(im),title('orginal image');

[x,y] = size(im);

for i=1:x
    for j=1:y
        if(im(i,j)<128)
            im(i,j)=im(i,j)-10;
            if(im(i,j)<0)
                im(i,j)=0;
            end
        else
            im(i,j) = im(i,j)+100;
            if(im(i,j)>255)
                 im(i,j) = 255;
            end
        end
    end
end

subplot(2,1,2)
imshow(im),title('contrast image')
                
        