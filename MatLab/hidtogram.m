im =  imread('bby.jpg')

subplot(3,1,1)
imshow(im),title('orginal image')

d = size(im);
n = d(1)*d(2);
pk = zeros(0,255)

for i=0:255
    g = find(im==i)
    [s a] = size(g)
    pk(i+1)=s/n
end

subplot(3,1,2)
bar(0:255,3*pk,'stack'),title('Histogram')

rgb  = zeros(size(im,1),size(im,2))
rgb = .298*im(:,:,1)+.587*im(:,:,2)+.114*im(:,:,3)

subplot(3,1,3)
imhist(rgb),title('histogram with func')