<?xml version="1.0" encoding="UTF-8"?>
<mxfile host="app.diagrams.net" modified="2025-01-30T12:00:00.000Z" agent="5.0" etag="abc123" version="24.0.0">
  <diagram name="Sequenzdiagramm" id="sequenzdiagramm">
    <mxGraphModel dx="1422" dy="794" grid="1" gridSize="10" guides="1" tooltips="1" connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="1200" pageHeight="1600" math="0" shadow="0">
      <root>
        <mxCell id="0" />
        <mxCell id="1" parent="0" />
        
        <!-- Titel -->
        <mxCell id="title" value="Sequenzdiagramm: Auto zum Fuhrpark hinzufügen" style="text;html=1;strokeColor=none;fillColor=none;align=center;verticalAlign=middle;whiteSpace=wrap;rounded=0;fontSize=16;fontStyle=1;" vertex="1" parent="1">
          <mxGeometry x="400" y="10" width="400" height="30" as="geometry" />
        </mxCell>
        
        <!-- Akteure (Lebenslinie-Header) -->
        <mxCell id="main_obj" value=":Main" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#fff2cc;strokeColor=#d6b656;" vertex="1" parent="1">
          <mxGeometry x="40" y="60" width="80" height="40" as="geometry" />
        </mxCell>
        
        <mxCell id="fuhrpark_obj" value=":Fuhrpark" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#dae8fc;strokeColor=#6c8ebf;" vertex="1" parent="1">
          <mxGeometry x="180" y="60" width="100" height="40" as="geometry" />
        </mxCell>
        
        <mxCell id="info_obj" value=":Info" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#d5e8d4;strokeColor=#82b366;" vertex="1" parent="1">
          <mxGeometry x="340" y="60" width="80" height="40" as="geometry" />
        </mxCell>
        
        <mxCell id="auto_obj" value=":Auto" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#f8cecc;strokeColor=#b85450;" vertex="1" parent="1">
          <mxGeometry x="480" y="60" width="80" height="40" as="geometry" />
        </mxCell>
        
        <mxCell id="eventargs_obj" value=":AutoHinzugefuegtEventArgs" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#e1d5e7;strokeColor=#9673a6;" vertex="1" parent="1">
          <mxGeometry x="620" y="60" width="180" height="40" as="geometry" />
        </mxCell>
        
        <mxCell id="linkedlist_obj" value=":LinkedList&lt;Auto&gt;" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#ffcc99;strokeColor=#d79b00;" vertex="1" parent="1">
          <mxGeometry x="860" y="60" width="120" height="40" as="geometry" />
        </mxCell>

        <!-- Lebenslinien -->
        <mxCell id="lifeline1" style="endArrow=none;dashed=1;html=1;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="80" y="120" as="sourcePoint" />
            <mxPoint x="80" y="1400" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="lifeline2" style="endArrow=none;dashed=1;html=1;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="230" y="120" as="sourcePoint" />
            <mxPoint x="230" y="1400" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="lifeline3" style="endArrow=none;dashed=1;html=1;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="380" y="120" as="sourcePoint" />
            <mxPoint x="380" y="1400" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="lifeline4" style="endArrow=none;dashed=1;html=1;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="520" y="120" as="sourcePoint" />
            <mxPoint x="520" y="1400" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="lifeline5" style="endArrow=none;dashed=1;html=1;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="710" y="120" as="sourcePoint" />
            <mxPoint x="710" y="1400" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="lifeline6" style="endArrow=none;dashed=1;html=1;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="920" y="120" as="sourcePoint" />
            <mxPoint x="920" y="1400" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Aktivierungsbalken -->
        <mxCell id="activation_main" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#fff2cc;strokeColor=#d6b656;" vertex="1" parent="1">
          <mxGeometry x="75" y="140" width="10" height="1200" as="geometry" />
        </mxCell>

        <!-- Nachrichten mit Nummerierung -->
        
        <!-- 1. Fuhrpark erstellen -->
        <mxCell id="msg1" value="1: new Fuhrpark()" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="85" y="160" as="sourcePoint" />
            <mxPoint x="225" y="160" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="activation_fuhrpark1" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#dae8fc;strokeColor=#6c8ebf;" vertex="1" parent="1">
          <mxGeometry x="225" y="160" width="10" height="40" as="geometry" />
        </mxCell>
        
        <!-- 2. LinkedList erstellen -->
        <mxCell id="msg2" value="2: new LinkedList&lt;Auto&gt;()" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="235" y="180" as="sourcePoint" />
            <mxPoint x="915" y="180" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 3. Info erstellen -->
        <mxCell id="msg3" value="3: new Info()" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="85" y="220" as="sourcePoint" />
            <mxPoint x="375" y="220" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="activation_info1" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#d5e8d4;strokeColor=#82b366;" vertex="1" parent="1">
          <mxGeometry x="375" y="220" width="10" height="20" as="geometry" />
        </mxCell>
        
        <!-- 4. Event Handler registrieren -->
        <mxCell id="msg4" value="4: AutoHinzugefuegt += infoAnzeige.AutoAufgenommenHandler" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="85" y="260" as="sourcePoint" />
            <mxPoint x="225" y="260" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="activation_fuhrpark2" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#dae8fc;strokeColor=#6c8ebf;" vertex="1" parent="1">
          <mxGeometry x="225" y="260" width="10" height="20" as="geometry" />
        </mxCell>
        
        <!-- 5. Auto erstellen -->
        <mxCell id="msg5" value="5: new Auto(&quot;BMW&quot;, 2022)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="85" y="300" as="sourcePoint" />
            <mxPoint x="515" y="300" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="activation_auto" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#f8cecc;strokeColor=#b85450;" vertex="1" parent="1">
          <mxGeometry x="515" y="300" width="10" height="40" as="geometry" />
        </mxCell>
        
        <!-- 6. Auto return -->
        <mxCell id="msg6" value="6: return auto" style="endArrow=open;dashed=1;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="515" y="330" as="sourcePoint" />
            <mxPoint x="85" y="330" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 7. Aufnehmen aufrufen -->
        <mxCell id="msg7" value="7: Aufnehmen(auto)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="85" y="360" as="sourcePoint" />
            <mxPoint x="225" y="360" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="activation_fuhrpark3" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#dae8fc;strokeColor=#6c8ebf;" vertex="1" parent="1">
          <mxGeometry x="225" y="360" width="10" height="400" as="geometry" />
        </mxCell>
        
        <!-- 8. Auto zur Liste hinzufügen -->
        <mxCell id="msg8" value="8: fahrzeuge.Add(auto)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="235" y="390" as="sourcePoint" />
            <mxPoint x="915" y="390" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="activation_linkedlist" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#ffcc99;strokeColor=#d79b00;" vertex="1" parent="1">
          <mxGeometry x="915" y="390" width="10" height="60" as="geometry" />
        </mxCell>
        
        <!-- 9. Console WriteLine -->
        <mxCell id="msg9" value="9: Console.WriteLine(&quot;Auto aufgenommen: {auto}&quot;)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="235" y="430" as="sourcePoint" />
            <mxPoint x="350" y="430" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 10. EventArgs erstellen -->
        <mxCell id="msg10" value="10: new AutoHinzugefuegtEventArgs(auto)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="235" y="470" as="sourcePoint" />
            <mxPoint x="705" y="470" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="activation_eventargs" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#e1d5e7;strokeColor=#9673a6;" vertex="1" parent="1">
          <mxGeometry x="705" y="470" width="10" height="40" as="geometry" />
        </mxCell>
        
        <!-- 11. EventArgs return -->
        <mxCell id="msg11" value="11: return args" style="endArrow=open;dashed=1;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="705" y="500" as="sourcePoint" />
            <mxPoint x="235" y="500" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 12. OnAutoHinzugefuegt aufrufen -->
        <mxCell id="msg12" value="12: OnAutoHinzugefuegt(args)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="235" y="530" as="sourcePoint" />
            <mxPoint x="235" y="550" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 13. Event Handler aufrufen -->
        <mxCell id="msg13" value="13: AutoHinzugefuegt.Invoke(this, args)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="235" y="570" as="sourcePoint" />
            <mxPoint x="375" y="570" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <mxCell id="activation_info2" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#d5e8d4;strokeColor=#82b366;" vertex="1" parent="1">
          <mxGeometry x="375" y="570" width="10" height="120" as="geometry" />
        </mxCell>
        
        <!-- 14. Info Console WriteLine -->
        <mxCell id="msg14" value="14: Console.WriteLine(&quot;--- Info: Neues Auto im Fuhrpark aufgenommen ---&quot;)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="385" y="600" as="sourcePoint" />
            <mxPoint x="500" y="600" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 15. Auto Daten ausgeben -->
        <mxCell id="msg15" value="15: e.HinzugefuegtesAuto.Hersteller" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="385" y="630" as="sourceSource" />
            <mxPoint x="705" y="630" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 16. Weitere Console Ausgaben -->
        <mxCell id="msg16" value="16: Console.WriteLine(weitere Auto-Daten)" style="endArrow=block;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="385" y="660" as="sourcePoint" />
            <mxPoint x="500" y="660" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 17. Return von Info -->
        <mxCell id="msg17" value="17: return" style="endArrow=open;dashed=1;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="375" y="690" as="sourcePoint" />
            <mxPoint x="235" y="690" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- 18. Return von Aufnehmen -->
        <mxCell id="msg18" value="18: return" style="endArrow=open;dashed=1;html=1;rounded=0;strokeWidth=2;" edge="1" parent="1">
          <mxGeometry x="0.1" width="50" height="50" relative="1" as="geometry">
            <mxPoint x="225" y="730" as="sourcePoint" />
            <mxPoint x="85" y="730" as="targetPoint" />
            <mxPoint as="offset" />
          </mxGeometry>
        </mxCell>
        
        <!-- Notizen -->
        <mxCell id="note1" value="Hinweis:&#xa;Das Event wird automatisch&#xa;an alle registrierten Handler&#xa;weitergeleitet" style="shape=note;whiteSpace=wrap;html=1;backgroundOutline=1;darkOpacity=0.05;fillColor=#fff2cc;strokeColor=#d6b656;" vertex="1" parent="1">
          <mxGeometry x="40" y="800" width="160" height="80" as="geometry" />
        </mxCell>
        
        <!-- Alt-Fragment -->
        <mxCell id="alt_frame" value="alt [Event-Handler registriert]" style="shape=umlFrame;whiteSpace=wrap;html=1;pointerEvents=0;fillColor=#f0f0f0;" vertex="1" parent="1">
          <mxGeometry x="200" y="540" width="400" height="180" as="geometry" />
        </mxCell>
        
      </root>
    </mxGraphModel>
  </diagram>
</mxfile>