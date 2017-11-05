<?php include 'database.php' ?>
<?php include 'home.php' ?>



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
         $db = new database();
         $query="select student.roll, student.name, student.dept, student.session, class_test.ct1, 
         class_test.ct2, class_test.ct3 
                from student
                  inner join class_test on student.roll=class_test.roll
                  inner join attendence on student.roll=attendence.roll
                ";

          $result = $db->select($query);

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
