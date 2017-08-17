<?php
Class Database{
	public $host   = DB_HOST;
	public $user   = DB_USER;
	public $pass   = DB_PASS;
	public $db = DB_NAME;
	
	
	public $link;
	public $error;


    public function __construct()
	{
		$this->connectDB();
	}
	

    public function connectDB()
	{
       $this->link = new mysqli($this->host, $this->user, $this->pass, $this->db);
       return $this->link;
    }
	



	// Select or Read data
	
	public function select($query)
	{
		$conn = new mysqli($this->host, $this->user, $this->pass, $this->db);
		if(mysqli_num_rows($conn)==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	


	public function insert($query)
	{
		$conn = new mysqli($this->host, $this->user, $this->pass, $this->db);

		if($conn->connect_error)
		{
			  die("Connection failed: " . $conn->connect_error);
		}
		else
		{
			if ($conn->query($sql) === TRUE) 
			{
			   header("Location: index.php?msg=".urlencode('Data Updated successfully.'));
			} 
			else 
			{
			    echo "Error: " . $sql . "<br>" . $conn->error;
			}
		}
    }
   
  
  // Delete data
   public function delete($query)
   {
       $conn = new mysqli($this->host, $this->user, $this->pass, $this->db);

		if($conn->connect_error)
		{
			  die("Connection failed: " . $conn->connect_error);
		}
		else
		{
			if ($conn->query($sql) === TRUE) 
			{
			   header("Location: index.php?msg=".urlencode('Data Updated successfully.'));
			} 
			else 
			{
			    echo "Error: " . $sql . "<br>" . $conn->error;
			}
		}
   }

 
 
}

