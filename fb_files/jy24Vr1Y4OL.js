/*!CK:2325336658!*//*1426597804,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["gMM99"]); }

__d("XIntlPostTranslationController",["XController"],function(a,b,c,d,e,f){b.__markCompiled&&b.__markCompiled();e.exports=b("XController").create("\/intl\/see_translation\/",{ftid:{type:"String",required:true}});},null);
__d("IntlPostTranslation",["AsyncRequest","cx","DOM","Event","fbt","highlight","LoadingIndicator.react","React","XIntlPostTranslationController"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o){b.__markCompiled&&b.__markCompiled();function p(r,s){var t=i.create('div',{'class':"_5yn0"},s||k._("Aucune traduction disponible"));i.replace(r,t);if(s)l(t);}var q={bindListener:function(r,s){j.listen(r,'click',function(){n.render(n.createElement(m,{size:"small",color:"white"}),r);var t=o.getURIBuilder().setString('ftid',s).getURI();new g().setURI(t).setHandler(function(u){var v=u.getPayload();p(r,v&&v.text);}).setErrorHandler(function(){p(r,null);}).send();});}};e.exports=q;},null);