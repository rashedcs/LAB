a=imread ('bby.jpg');
b = imresize (a, [400,400]);
c=imread ('download.jpg');
d= imresize (c, [400,400]);
e=imadd (b,d); 

subplot(2,1,1)
imshow(e),title('image add func');

[x1, y1, z1] = size(b)
[x2, y2, z2] = size(d)

for i = 1: x1
   for j = 1: y1
      for k = 1: z1
          im3(i, j, k) = b(i, j, k) + d(i, j, k);
      end
   end
end

subplot(2,1,2)
imshow(im3),title('image add no func');