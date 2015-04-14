<?php

class IBE_template
{

    private $registry;
    private $scripts=array();
    private $scriptsfiles=array();
    private $vars = array();

    function __construct($registry)
    {
        $this->registry = $registry;
    }

    function set($varname, $value, $overwrite=false)
    {
        if (isset($this->vars[$varname]) == true AND $overwrite == false)
        {
            throw new Exception('Unable to set var `' . $varname . '`. Already set, and overwrite not allowed.');
            return false;
        }
        $this->vars[$varname] = $value;
        return true;
    }
    function add_script($script,$isfile)
    {
        if($isfile)
            $this->scriptsfiles[]=$script;
        else
            $this->scripts[]=$script;
    }

    function remove($varname)
    {
        unset($this->vars[$varname]);
        return true;
    }

    function show($name,$dir='')
    {
        if($dir!='')
            $dir=$dir.DIRECTORY_SEPARATOR;
        $path = $this->registry['templatespath'] .$dir.'tpl_'. $name . '.php';
		//echo $path;
        if (file_exists($path) == false)
        {
            throw new Exception('Template `' . $name . '` does not exist.');
            return false;
        }

        // Load variables
        $IBE_SCRIPTSPATH=$this->registry['scriptswebpath'];
        $IBE_BASEURL=$this->registry['baseurl'];
        $IBE_SCRIPTS=$this->scripts;
        $IBE_SCRIPTSFILES=$this->scriptsfiles;

        foreach ($this->vars as $key => $value)
        {
            $$key = $value;
        }

        include ($path);
    }

}

?>
