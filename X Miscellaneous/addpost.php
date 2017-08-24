<?php include 'header.php'; ?>



<?php
      include '../lib/database.php';
      $db = new database();

      if(isset($_POST["Submit"]))
      {
        $title = mysqli_real_escape_string($db->link, $_POST['title']);
        $cat = mysqli_real_escape_string($db->link, $_POST['cat']);
        $body = mysqli_real_escape_string($db->link, $_POST['mytextarea']);
        $author = mysqli_real_escape_string($db->link, $_POST['author']);
        
        /*
        $permitted = array('jpg', 'jpeg', 'png', 'gif');
        $file_name = $_FILES['image']['name'];
        $file_size = $_FILES['image']['size'];
        $file_temp = $_FILES['image']['tmp_name'];

        
        $div = explode('.', $file_name);
        $file_ext = strtolower(end($div));
        $unique_image = substr(md5(time()), 0, 10).'.'.$file_ext;
        $uploaded_image = "uploads/".$unique_image;
       

        if($title == '' || $body == '' || $cat == '' || $author == '')
        {
          $error = 'Please fill out all required fields';
        } 
         */

            $query = "INSERT INTO tbl_post(cat, title, body, author, date) 
                      VALUES('$cat','$title','$body' ,
                      '$author', 'NOW()')";
            $inserted_rows = $db->insert($query);
            if($inserted_rows)
            {
                 echo "<span class='success'>Post Inserted Successfully </span>" ;
            }
            else
            {
                 echo "<span class='error'>Post Not Inserted !</span>" ;
            }
   
        /*
        else if($file_size>1048567)
        {
          echo "Image size should be less than 1mb";
        }
        else if(in_array($file_ext, $permited)==false)
        {
          echo "<span class='error'>You can upload only:-".implode(', ', $permited)."</span>";
        }
        else
        {
            move_uploaded_file($file_tmp, $uploaded_image);
            $query = "INSERT INTO tbl_post(cat, title, body, image, author, date) 
                      VALUES('$cat','$title','$body' '$uploaded_image',
                      '$author', 'NOW()')";
            $inserted_rows = $db->insert($query);
            if($inserted_rows)
            {
               echo "<span class='success'>Post Inserted Successfully. </span>";
            }
            else
            {
                echo "<span class='error'>Post Not Inserted !</span>";
            }
        }
         */
      }
?>

<?php
 $query = "select * from tbl_catagory";
 $categories = $db->select($query);
?>

<head>
  <title>Bootstrap Example</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="css/bootstrap.min.css">
  <script src="js/bootstrap.min.js"></script>
  <script src='https://cloud.tinymce.com/stable/tinymce.min.js'></script>
  <script>
  tinymce.init({
    selector: '#mytextarea'
  });
  </script>
</head>

 </head>


<div class="container">
  <h2>Add a post</h2>

  <form action="" method="POST">

     <div class="form-group">
       <label for="title">Post Title</label>
       <input name="title" class="form-control" id="title" type="text">
     </div>

     <div class="form-group">
       <label for="cat">Catagory</label>
       <select  name="cat" class="form-control" id="cat">
         <?php while($row = $categories->fetch_assoc()) :  ?>
           <?php if($row['id'] == $post['category'])
           {
             $selected = 'selected';
           } 
           else 
           {
             $selected = '';
           }
           ?>  
          <option 
            value="<?php echo $row['id']; ?>"><?php echo $row['name']; ?>
         </option>
        <?php  endwhile; ?>
      </select>
    </div>


     <div class="form-group">
       <label for="mytextarea">Post Body</label>
       <textarea name="mytextarea" id="mytextarea"> </textarea>
     </div>


     <div class="form-group">
       <label for="author">Author</label>
       <select name="author" class="form-control" id="author">
         <option 
            value="<?php echo $_SESSION['id']; ?>"><?php echo $_SESSION['username']; ?>
         </option>
      </select>
    </div>

   <div>
     <button type="submit" class="btn btn-default">Submit</button>
   </div>

  </form>
</html>

<?php include 'footer.php'; ?>
