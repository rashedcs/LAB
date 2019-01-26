a= imread('download.jpg');

b  = zeros(size(a,1),size(a,2))
b = .298*a(:,:,1)+.587*a(:,:,2)+.114*a(:,:,3)
subplot(3,1,1),imshow(b),title('Input image');

h=[-1 -1 -1; 0 0 0; 1 1 1];
h = h.';

c=imfilter(b,h);
subplot(3,1,2),imshow(c),title('edge detected image');

d = edge(b,'Prewitt');
subplot(3,1,3),imshow(d),title('edge detected image2');