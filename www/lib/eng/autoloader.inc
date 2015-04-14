<?php
class IBE_Autoloader
{
    private static $registry;

    public static function SetRegistry($reg)
    {
        self::$registry=$reg;
    }
    public static function Autoload($name)
    {
        if(trim($name)=='')
            return;
        $parts=explode('_',$name);
        if ($parts===false||!is_array($parts))
            return;
        $cnt=count($parts);
        if($cnt<2)
            return;
       
        switch ($parts[$cnt-2])
        {
            case 'textstr':
            case 'validator':
            case 'utils':
                require_once self::$registry['libpath'].$parts[$cnt-2].'/'.$parts[$cnt-2].'_'.$parts[$cnt-1].'.inc';
                break;
            case 'settings':
                require_once self::$registry['libpath'].'eng/settings/settings_'.$parts[$cnt-1].'.inc';
                break;
            case 'model':
                require_once self::$registry['engpath'].'/models/model_'.$parts[$cnt-1].'.inc';
                break;
        }

    }
}
?>
