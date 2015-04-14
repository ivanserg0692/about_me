<?php
require_once 'enginesettings.inc';
class IBE_Router
{
    private $registry;
    private $path;


    function  __construct($registry)
    {
        $this->registry=$registry;
    }

    //установить путь к контроллерам
    public function SetControllersPath($path)
    {
        $path=rtrim ($path,'\\/');
        //echo $path;
        $path.=DIRSEP;
     //   echo $path;
        if (is_dir($path)==false)
        {//нет папки с контроллерами
            throw new Exception('Invalid controllers path `'.$path.'`');
        }
        $this->path=$path;
    }

    


    function Run($url,$baseurl)
    {
        if(strpos($url, '?')!==false)
        {
            $url=explode('?',$url);
            $url=$url[0];
        }
        //получаем контроллер
        $this->GetController($url,$baseurl,$path,$controller,$action,$args);
        //проверяем доступность файла для чтения
        if (is_readable($path)==false)
            die ('404 Not Found');//не нашелся контроллер

        include ($path);
        $ctrclassname=IBE_DEFCTRCLASSPREF.$controller;

        //var_dump($action);
        //таки запуск

        $this->registry->set('args',$args);
        $controller=new $ctrclassname($this->registry);
        if (method_exists($controller,$action))
            $controller->$action();
        else
            throw new Exception('No action');

    }
    //получаем контроллер
    private function GetController($url,$baseurl,&$path,&$controller,&$action,&$args)
    {
        $url=urlhlp_GetServiceName($url,$baseurl);
        $ctrwebpath;
        if ($url=='')
            $controller='index';


        $route = trim($url, '/\\'); //удаляем слеши из внечале  строки с url
        $parts = explode('/', $route); //разделяем на блоки отделенные слешами
		//var_dump($parts);


        // ������� ���������� ����������

        $cmd_path = $this->path;
        $ctrwebpath=$baseurl;
        foreach ($parts as $part)
        {
            $fullpath = $cmd_path . $part;
      //      $ctrwebpath.=$part.DIRSEP;

            if (is_dir($fullpath))
            {
                
                $cmd_path .= $part . DIRSEP;
                $ctrwebpath.=$part . DIRSEP;
                array_shift($parts);
             //   var_dump($ctrwebpath);
               // echo 'dir<br>';
                continue;
            }


            // ������� ����

            if (is_file($fullpath . '.php'))
            {

                $controller = $part;

                array_shift($parts);


                break;
            }
        }

      //  var_dump($controller);

        /*echo('ar<br>');
        var_dump($parts);
        echo('ctrl<br>');
        var_dump($controller);*/

        $action = array_shift($parts);
        if (empty($controller))
        {
            $controller = 'index';
        };
        /*echo('ctrl<br>');
        var_dump($controller);
        echo('$fullpath<br>');
        var_dump($fullpath);*/
       


        if (empty($action))
        {
            $action = 'Run';
        }
       // echo('action');
        //var_dump($action);

     //   echo '$cmd_path';
      //  var_dump($cmd_path);
      //  echo('crtweb<br>');
      //  var_dump($ctrwebpath);
        $path = $cmd_path . $controller . '.php';
      //  echo 'file='.$path.'<br>';

        $args = $parts;
        $this->registry['IBE_WEBPATH']=$ctrwebpath;
       
        
     //   var_dump($args);
    }
}

?>
