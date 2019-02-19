im=imread('C:\Users\Rashed\Downloads\1.jpg');

subplot(3,1,1), imshow(im),title('orginal image')

[x y] = size(im);
%d = size(im);
%n = d(1)*d(2);
n = x*y; 
pk = zeros(0,255);

for i=0:1:255
    g = find(im==i)
    [nk a] = size(g)
    pk(i+1)=nk/n
end

subplot(3,1,2), bar(0:255,10*pk,'stack'),title('Histogram')





rgb  = zeros(size(im,1),size(im,2))
rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3)

subplot(3,1,3)
imhist(rgb),title('histogram with func')
