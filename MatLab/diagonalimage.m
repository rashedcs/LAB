im = imread('C:\Users\Rashed\Downloads\1.jpg');
im = rgb2gray(im);
subplot(2,1,1), imshow(im), title('Orginal image');

[x, y] = size(im);

for i = 1:1:x
    for j = 1:1:y
         if (i == j)           im(i,j) = 255;
         elseif (i+j == y+1)   im(i,j) = 255;
         end
    end
end

subplot(2,1,2), imshow(im), title('Diagonal mark image');
