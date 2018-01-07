<?php include 'database.php' ?>
<?php include 'home.php' ?>



<?php 
    $num_rec_per_page=4;
    $db = new database();

    if(isset($_GET["page"])) 
    { 
      $page  = $_GET["page"]; 
    } 
    else 
    { 
      $page=1; 
    }; 
    $start_from = ($page-1) * $num_rec_per_page; 
    $sql="select student.roll, student.name, student.dept, student.session, 
          class_test.ct1, class_test.ct2, class_test.ct3 
                    from student
                      inner join class_test on student.roll=class_test.roll
                      inner join attendence on student.roll=attendence.roll
                   LIMIT $start_from, $num_rec_per_page ";

    $result = $db->select($sql); 
    $count_row =  mysqli_num_rows($result); 
?> 

<div class="container">
 <table class="table table-bordered">
    <thead>
         <tr>
           <th>ID</th>
           <th>Name</th>
           <th>Department</th>
           <th>Session</th>
         </tr>
    </thead>

    <tbody>
      <?php
        while($row = mysqli_fetch_array($result)) 
        {
           echo "<tr>";
           echo "<td> $row[name]</td>";
           echo "<td> $row[roll]</td>";
           echo "<td> $row[dept]</td>";
           echo "<td> $row[session]</td>";
           echo "</tr>";
        }    
      ?>   
    </tbody>
  </table>
</div>


<div id="content"></div>
<div id="pagination">
<ul class="pagination">

<?php   
  $query="select student.roll, student.name, student.dept, student.session, 
          class_test.ct1, class_test.ct2, class_test.ct3 
                    from student
                      inner join class_test on student.roll=class_test.roll
                      inner join attendence on student.roll=attendence.roll
                   LIMIT $start_from, $num_rec_per_page ";
  $query = $db->select($sql);
  $total_records = mysqli_num_rows($query);;  //count number of records
  $total_pages = ceil($total_records / $num_rec_per_page); 
  echo "<a href='show.php?page=1'>".'|<'."</a> ";  
  for ($i=1; $i<=$total_pages; $i++) 
  { 
       echo "<a href='show.php?page=".$i."'>".$i."</a> "; 
  }; 
  echo "<a href='show.php?page=$total_pages'>".'>|'."</a> "; // Goto last page
?>
</ul>
</div>
</div>

