   M S B A M L   `   `   `  ����I  EHamburgerMenu2, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null/clr-namespace:HamburgerMenu2HamburgerMenu2  5   	       HamburgerMenu2.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   V RMaterialDesignThemes.Wpf, Version=3.1.3.1513, Culture=neutral, PublicKeyToken=nullFmaterialDesign1http://materialdesigninxaml.net/winfx/xaml/themes  5   	   (localclr-namespace:HamburgerMenu2  5   	     � Title$  
MainWindow��5	   	   $	��600��6   $
��1080��6)    � WindowStyle$
 None=�66   
������� � 	Resources 5         MenuOpen �� TargetProperty �� 
TargetName9  3System.Windows.Media.Animation.EasingDoubleKeyFrame O� KeyTime O� Value  	MenuClose��%�  &	        &	 �     �� 5   
   .��5      U� $ (FrameworkElement.Width)�6,   $ GridMenu��6a   .\�5        $ 0��6'   $ 70Q�63     5      $ 0:0:0.5��6'   $	 200Q�69   5      5      �� 5   
   .��5      U� $ (FrameworkElement.Width)�6,   $ GridMenu��6a   .\�5        $ 0��6'   $	 200Q�63     5      $ 0:0:0.5��6'   $ 70Q�69   5      5      5       � Triggers 5      :� 5   
    :� RoutedEvent$ ButtonBase.Click��6   	 :� 
SourceName$	 ButtonOpenMenu��66   .[�5      �� #��[  6   5      :� 5   
   $ ButtonBase.Click��6   $	 ButtonCloseMenu��66   .[�5      �� #��[ 6   5       .��5#      � 
�������.+�5$   
   � -   5        
 �Name$
 GridMain��5$      $��Right=�6!   $��Bottom=�6=   $	��540��6X   $
��1010��6e   � 5&   
   -   5        $
 GridTop��5&      $��70��6    $	��Top=�6,   
����  � J� Effect 5'      3  -System.Windows.Media.Effects.DropShadowEffect  5(         
BlurRadius$ 1Q�6#      ShadowDepth$ 1Q�62      Color$ 	#FFACACAC��6B   .+�5*      �� $��Design com WPF��6   $��Center=�6.   $��Center=�6I   $��22(�6f   5+      �� 5,      $��Center=�6    �� Orientation$ 
Horizontal=�64   $��Right=�6M   .+�5-      �� $��Anderson Paschoalon��6   $��Center=�67   $��18(�6R   '  !MaterialDesignThemes.Wpf.PopupBox  5.         PlacementMode$ BottomAndAlignRightEdges=�6+      	StaysOpen .  $��10q�6f      PopupContent. 5/      �� $	��150��6!   .+�50      �� $��Account��6!   �� 51      $��Settings��6!   �� 52      $
��Help��6!   �� 53      �� 54      -   5         ��Name$ ButtonPopUpLogout��54   !   $��Logout��6<   6M   55      56      57      58      � 5:   
   -   5        $
 GridMenu��5:      $��60��6!   $
��Left=�6,   
����� �.+�5;      �� .+�5<      � $	��150��6   
�������.+�5=      �� -   5        $ ButtonCloseMenu��5=      $��60��66   $��60��5>      $	��Top=�6)   $��Right=�5?      $y�	Collapsed=�5@   4   ��5?   9   Z� ��5@      Z� .��5B      '  !MaterialDesignThemes.Wpf.PackIcon  
����� �   Kind$ 	ArrowLeft=�6I   $��25��6Z   $��25��6e   5C      �� 5D      -   5        $ ButtonOpenMenu��5D      $��60��65   $��60��5E      $	��Top=�6)   $��Right=�5F      $y�Visible=�5G   5   ��5F   9   Z� ��5G      Z� .��5I        
����� �$
 Menu=�6I   $��25��6U   $��25��6`   5J      5K      �� 5L      -   5         ��Name$ ListViewMenu��5L      $��Disabled=�61   
����  �.@�5N      �� -   5         ��Name$ ItemHome��5N   #   $��60��65   .��5O      �� $ 
Horizontal=�6%   .+�5P        $ ViewDashboard=�66   $��25��6K   $��25��6V   $��10q�6b   $��Center=�6n   �� 5Q      $
��Home��6(   $��Center=�64   $��20 10q�6O   5R      5S      �� 5T      -	   5        $ 
ItemPencil��5T   #   $��60��68   .��5U      �� $ 
Horizontal=�6%   .+�5V        $ Pencil=�66   $��25��6D   $��25��6O   $��10q�6[   $��Center=�6g   �� 5W      $��Pencil��6(   $��Center=�66   $��20 10q�6Q   5X      5Y      �� 5Z      -
   5        $ 
ItemTicket��5Z   #   $��60��67   .��5[      �� $ 
Horizontal=�6%   .+�5\        $ Ticket=�66   $��25��6D   $��25��6O   $��10q�6[   $��Center=�6g   �� 5]      $��Ticket��6(   $��Center=�66   $��20 10q�6Q   5^      5_      �� 5`      -   5        $ ItemMessages��5`   #   $��60��69   .��5a      �� $ 
Horizontal=�6%   .+�5b        $ Message=�66   $��25��6E   $��25��6P   $��10q�6\   $��Center=�6h   �� 5c      $��Messages��6(   $��Center=�68   $��20 10q�6S   5d      5e      �� 5f      -   5        $ 
ItemGitHub��5f   #   $��60��67   .��5g      �� $ 
Horizontal=�6%   .+�5h        $ Github=�66   $��25��6D   $��25��6O   $��10q�6[   $��Center=�6g   �� 5i      $��GitHub��6(   $��Center=�66   $��20 10q�6Q   5j      5k      5l      5m      5n      5o      5r      