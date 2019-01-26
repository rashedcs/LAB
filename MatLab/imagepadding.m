im = imread('im2.jpg')

rgb  = zeros(size(im,1),size(im,2))
rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3)
subplot(2,1,1)
imshow(rgb),title('orginal image');

[x y] = size(rgb);

for i=1:x
    for j=1:y
        if(i<=6 || j<=6 || i>=x-6 || j>=y-6)
        %if(i==1 || i==x || j==y || j==1)
            rgb(i,j) = 0;
        end
    end
end


subplot(2,1,2)
imshow(rgb),title('after pading');

