%image=imread('C:\Users\Rashed\Downloads\1.jpg');
a=imread ('C:\Users\Rashed\Downloads\1.jpg');
b = imresize (a, [400,400]);
c=imread ('C:\Users\Rashed\Downloads\2.jpg');
d= imresize (c, [400,400]);

%e=imadd (b,d); 
%subplot(2,1,1),imshow(e),title('image add func');

%[x1, y1] = size(b) %[x1, y1, z1] = size(b)
%[x2, y2] = size(d) %[x2, y2, z1] = size(d)

for i = 1:1:400
   for j = 1:1:400
      %for k = 1: z1
           %im3(i, j, k) = b(i, j, k) + d(i, j, k);
           im3(i, j) = b(i, j) + d(i, j);
      %end
   end
end

subplot(2,1,2), imshow(im3),title('image add no func');
