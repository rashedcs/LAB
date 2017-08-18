<?php
class database
{
	  public $host = DB_HOST;
	  public $user = DB_USER;
	  public $password = DB_PASS;
	  public $dbname = DB_NAME;

	  public $link;
	  public $error;
  
	  private function connectionDB()
	  {
	     $this->link = new mysql($this->host, $this->user, $this->pass, $this->dbname):
	  }

          if(!$this->link)
          {
             $this->error ="Connection fail" . $this->link->connect_error;
             return false;
	  }
}
?>

